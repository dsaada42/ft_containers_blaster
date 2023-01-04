#!/bin/bash

EOC="\e[0m"
BOLD="\e[1m"
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"

#----- Path to containers hpp files -----
CONTAINER_PATH="../containers/includes"

#----- Compilation parameters -----
CXX="c++"
CXXFLAGS="-Wall -Wextra -Werror -std=c++98"
INCLUDES="-I${CONTAINER_PATH} -I."

#----- Printer functions -----
center() {
  termwidth="$(tput cols)"
  padding="$(printf '%0.1s' ={1..500})"
  printf "${BOLD}${YELLOW}%*.*s %s %*.*s${EOC}\n" \
  0 "$(((termwidth-2-${#1})/2))" "$padding" "$1" 0 "$(((termwidth-1-${#1})/2))" "$padding"
}
print_test_info(){
    columns=$(tput cols)
    field1=$(($columns * 80 / 100 - 1 ))
    field2=$(($columns * 10 / 100 - 1 ))
    field3=$(($columns * 10 / 100 - 1 ))
    fill=$(printf '%0.1s' ={1..500})

    printf "${BOLD}${YELLOW}|%-*s|%-*s|%-*s|${EOC}\n" \
        $field1 "Test" $field2 "Compile" $field3 "Diff"
    printf "${BOLD}${YELLOW}%-.*s${EOC}\n" $columns $fill

}

print_fail() {
    columns=$(tput cols)
    field1=$(($columns * 80 / 100 - 1 ))
    field2=$(($columns * 10 / 100 - 1 ))
    field3=$(($columns * 10 / 100 - 1 ))

    printf "|${RED}%-*s${EOC}|${GREEN}${BOLD}%-*s${EOC}|${RED}${BOLD}%-*s${EOC}|\n" \
        $field1 "$1" $field2 "OK" $field3 "OK"
}
print_error_compile() {
    columns=$(tput cols)
    field1=$(($columns * 80 / 100 - 1 ))
    field2=$(($columns * 10 / 100 - 1 ))
    field3=$(($columns * 10 / 100 - 1 ))

    printf "|${RED}%-*s${EOC}|${RED}${BOLD}%-*s${EOC}|${RED}${BOLD}%-*s${EOC}|\n" \
        $field1 "$1" $field2 "KO" $field3 "KO"
}
print_success() {
    columns=$(tput cols)
    field1=$(($columns * 80 / 100 - 1 ))
    field2=$(($columns * 10 / 100 - 1 ))
    field3=$(($columns * 10 / 100 - 1 ))

    printf "|${GREEN}%-*s${EOC}|${GREEN}${BOLD}%-*s${EOC}|${GREEN}${BOLD}%-*s${EOC}|\n" \
        $field1 "$1" $field2 "OK" $field3 "OK"
}

#----- Executes one test -----
run_test() {
    container=$1
    test_name=$2
    file=$3
    debug=$4

    if [ "$debug" = true ]; then
        #__ Test for ft and std__
        for namespace in ft std; do
            if ${CXX} ${CXXFLAGS} ${INCLUDES} -DNAMESPACE=$namespace -o ${file%.*} $file; then
                if ! ${file%.*} > ./logs/$1/$namespace/${test_name}.log; then
                    print_fail "$1 ${test_name}"
                    return
                fi
            else
                print_error_compile "$container $test_name"
                return
            fi
            rm ${file%.*}
        done
    else
        #__ Test for ft and std__
        for namespace in ft std; do
            if ${CXX} ${CXXFLAGS} ${INCLUDES} -DNAMESPACE=$namespace -o ${file%.*} $file 2> /dev/null; then
                if ! ${file%.*} > ./logs/$1/$namespace/${test_name}.log; then
                    print_fail "$1 ${test_name}"
                    return
                fi
            else
                print_error_compile "$container $test_name"
                return
            fi
            rm ${file%.*}
        done
    fi

    #__ Diff file __
    diff_file="./diffs/$1/${test_name}.diff"
    diff -u ./logs/$1/ft/${test_name}.log ./logs/$1/std/${test_name}.log > $diff_file
    res=$(cat $diff_file | wc -l)
    if [ $res -ne "0" ]; then
        print_fail "$container $test_name"
    else
        print_success "$container $test_name"
        rm -f $diff_file
    fi
}

#----- For a given container executes tests for ft and std -----
test_container() {
    #----- Creates log and diff folder if not exist -----
    mkdir -p ./logs/$1/ft
    mkdir -p ./logs/$1/std
    mkdir -p ./diffs/$1/

    center $(echo $1 | tr '[:lower:]' '[:upper:]')
    print_test_info

    files=$(find "tests/$1" -type f -name '*.cpp' 2>/dev/null | sort )

    if [ ${#files} == 0 ]; then
        echo "No tests found for container $1"
        return
    fi

    for file in $files
    do 
        test_name=$(basename ${file%.*})
        run_test $1 $test_name $file
    done        
}

#----- Tests all containers -----
test_containers() {

    containers="vector stack map set"

    for i in $containers;
    do
        test_container $i
    done
}

$*
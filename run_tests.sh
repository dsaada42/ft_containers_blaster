#!/bin/bash

#----- Path to containers hpp files -----
CONTAINER_PATH="../containers/includes"

#----- Compilation parameters -----
CXX="c++"
CXXFLAGS="-Wall -Wextra -Werror -std=c++98"
INCLUDES="-I${CONTAINER_PATH} -I."

#----- Printer functions -----
print_fail() {
    echo $1: FAILURE
}
print_error() {
    echo Error: $1
}
print_success() {
    echo $1: SUCCESS
}

#----- Executes one test -----
run_test() {
    container=$1
    test_name=$2
    file=$3

    #__ Test for ft __
    if ${CXX} ${CXXFLAGS} ${INCLUDES} -DNAMESPACE=ft -o ${file%.*} $file; then
        if ! ${file%.*} > ./logs/$1/ft/${test_name}.log; then
            print_fail "$1 ${test_name}"
            return
        fi
    else
        print_error "error compiling ${file%.*}"
        return
    fi
    #__ Test for std __
    if ${CXX} ${CXXFLAGS} ${INCLUDES} -DNAMESPACE=std -o ${file%.*} $file; then
        if ! ${file%.*} > ./logs/$1/std/${test_name}.log; then
            print_fail "$1 ${test_name}"
            return
        fi
    else
        print_error "error compiling ${file%.*}"
        return
    fi

    rm ${file%.*}
    #__ Diff file __
    diff_file="./diffs/$1/${test_name}.diff"
    diff -u ./logs/$1/ft/${test_name}.log ./logs/$1/std/${test_name}.log > $diff_file
    res=$(cat $diff_file | wc -l)
    if [ $res -ne "0" ]; then
        print_fail "$container $test_name"
        print_error "Check $diff_file for diff with std"
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
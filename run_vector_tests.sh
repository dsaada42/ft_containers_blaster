#!/bin/bash

#----- Path to containers hpp files -----
CONTAINER_PATH="../containers/includes"

#----- Compilation parameters -----
CXX="c++"
CXXFLAGS="-Wall -Wextra -Werror -std=c++98"
INCLUDES="-I${CONTAINER_PATH} -I."

#----- Creates log and diff folder if not exist -----
mkdir -p ./logs/vector/ft
mkdir -p ./logs/vector/std
mkdir -p ./diffs/vector/

#----- For each test file, execute test for ft and std -----
for file in $@
do
    test_name=$(basename ${file%.*})
    #__ Test for ft __
    if ${CXX} ${CXXFLAGS} ${INCLUDES} -DNAMESPACE=ft -o ${file%.*} $file; then
        if ! ${file%.*} > ./logs/vector/ft/${test_name}.log; then
            print_fail "vector ${test_name}"
            return
        fi
    else
        print_error "error compiling ${file%.*}"
        return
    fi
    #__ Test for std __
    if ${CXX} ${CXXFLAGS} ${INCLUDES} -DNAMESPACE=std -o ${file%.*} $file; then
        if ! ${file%.*} > ./logs/vector/std/${test_name}.log; then
            print_fail "vector ${test_name}"
            return
        fi
    else
        print_error "error compiling ${file%.*}"
        return
    fi

    rm ${file%.*}
    #__ Diff file __
    diff -u ./logs/vector/ft/${test_name}.log ./logs/vector/std/${test_name}.log > ./diffs/vector/${test_name}.diff
done


#!/bin/bash

# The pwd must be the repository folder for the script to work

set -e    # halt on first error

# use 'g++' as the compiler
CPP='g++'

# be aggressive about warnings and errors
W_FLAGS='-Wall -Wextra -Werror -Wfatal-errors -Wpedantic -pedantic-errors -fdiagnostics-show-location=once -std=c++11'

# clear out old object files
rm ./source/*.o

git log | head -1 > name.txt

# compile
$CPP -c ./source/main.cpp -o ./source/main.o $W_FLAGS
$CPP -o ./binaries/Linux_Binary_ ./source/main.o $W_FLAGS

#!/bin/bash

if [[ -z $1 ]];
then 
	TEST_DIR=test
else
	TEST_DIR=$1
fi

shopt -s nullglob
EXIT_CODE=0

echo "RUNNING TESTS in $TEST_DIR directory..."
echo "======================================="

for t in `echo $TEST_DIR/*.c`; do
	echo "Test file: $t"
	# TODO: add test config; remove hardcoded libs
	gcc -o tst $t *.c -Wl,-rpath,/usr/local/lib -ld4t4-5tructur35 && ./tst
	EXIT_CODE=`! (( $EXIT_CODE | $? )); echo $?`
	rm -f ./tst
	echo "---------------------------------------"
done


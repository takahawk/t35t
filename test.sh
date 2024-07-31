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
	# TODO: *.c is quickfix. figure out something cleaner
	gcc -o tst $t *.c && ./tst
	EXIT_CODE=`! (( $EXIT_CODE | $? )); echo $?`
	rm -f ./tst
	echo "---------------------------------------"
done


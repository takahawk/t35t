#!/bin/bash

if [[ -z $1 ]];
then 
	TEST_DIR=test
else
	TEST_DIR=$1
fi

EXIT_CODE=0

echo "RUNNING TESTS in $TEST_DIR directory..."
echo "======================================="

for t in `echo $TEST_DIR/*.c`; do
	echo "Test file: $t"
	gcc -o tst $t && ./tst
	EXIT_CODE=`! (( $EXIT_CODE | $? )); echo $?`
	rm -f ./tst
	echo "---------------------------------------"
done

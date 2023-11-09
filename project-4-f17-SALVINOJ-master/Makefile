# Makefile for HashTable tests

# Uncomment the tests as you're ready for them

all:
	gcc -o createTest tests/createTest.c hashtable.c -Wall -Werror -I .
	gcc -o insertTest tests/insertTest.c hashtable.c -Wall -Werror -I .
	gcc -o lookupTest tests/lookupTest.c hashtable.c -Wall -Werror -I .
	gcc -o failedLookupTest tests/failedLookupTest.c hashtable.c -Wall -Werror -I .
	gcc -o removeTest tests/removeTest.c hashtable.c -Wall -Werror -I .
	gcc -o failedRemoveTest tests/failedRemoveTest.c hashtable.c -Wall -Werror -I .
	gcc -o multipleInsertTest tests/multipleInsertTest.c hashtable.c -Wall -Werror -I .
	gcc -o multipleLookupTest tests/multipleLookupTest.c hashtable.c -Wall -Werror -I .
	gcc -o multipleRemoveTest tests/multipleRemoveTest.c hashtable.c -Wall -Werror -I .
	gcc -o memoryLeakTest tests/memoryLeakTest.c hashtable.c -Wall -Werror -I .

clean:
	rm createTest
	
	# Add commands here to remove executables
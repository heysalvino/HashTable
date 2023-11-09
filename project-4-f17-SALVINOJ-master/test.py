#####  DO NOT EDIT THIS FILE  #####
#####  DO NOT EDIT THIS FILE  #####
#####  DO NOT EDIT THIS FILE  #####
#####  DO NOT EDIT THIS FILE  #####
#####  DO NOT EDIT THIS FILE  #####

### CMS 230 automated testing program, ver. 1.0
### DSM, 2017

from os import system
from os import listdir
import sys
from sys import exit

# List of executable files
programs = ['createTest', 'insertTest', 'lookupTest', 'removeTest',
            'failedLookupTest', 'failedRemoveTest', 'multipleInsertTest',
            'multipleLookupTest', 'multipleRemoveTest', 'memoryLeakTest']

# Lists of tests in the tests/ directory associated with each program
tests = {'createTest':['createTest'],
         'insertTest':['insertTest'],
         'lookupTest':['lookupTest'],
         'removeTest':['removeTest'],
         'failedLookupTest':['failedLookupTest'],
         'failedRemoveTest':['failedRemoveTest'],
         'multipleInsertTest':['multipleInsertTest'],
         'multipleLookupTest':['multipleLookupTest'],
         'multipleRemoveTest':['multipleRemoveTest'],
         'memoryLeakTest':['memoryLeakTest']
}
	     
test_file_list = listdir('./tests')

num_passed = 0
final_return_code = 0

# Remove existing executables
print '\n#####  Removing any existing executables with make clean #####'
system('make clean')

# Build the project
print '\n#####  Building with make  #####'
rc = system('make')
if rc != 0:
	print 'Build failed. Exiting.'
	exit(1)
	
# A working build is one of the tests
print '\nBuild passed.',
num_passed += 1 

for program in programs:
	
	print '\n\n#####  Testing program %s  #####' % program

	for test in tests[program]:
		print '\n###  Test %s  ###' % test
		out_file = test + '.out'
		in_file = test + '.in'
		cmp_file = './tests/' + test + '.cmp'
		
		if in_file in test_file_list:
			run_command = './%s < ./tests/%s > %s' % (program, in_file, out_file)
		else:
			run_command = './%s > %s' % (program, out_file)
			
		# diff compares two files and reports if they are different
		# -Z ignores trailing whitespace
		# -q gives same/different reporting
		diff_cmd = 'diff -Z -q %s %s' % (out_file, cmp_file)
		
		system(run_command)
		rc = system(diff_cmd)

		if rc == 0:
			print 'Passed.'
			num_passed += 1
		else:
			final_return_code = 1  # Return 1 if any tests fail
			
		#print '\nTest input:'
		#system('cat %s' % './tests/' + in_file)	
		print '\nYour program\'s output:'
		system('cat %s' % out_file)
		print '\n\nExpected output:'
		system('cat %s' % cmp_file)

print '\n\n#####  Final Score  #####'
num_tests = sum([len(x) for x in tests.values()]) + 1
print 'You passed %d out of %d tests.' % (num_passed,  num_tests)
print 'Percentage = %f' % (float(num_passed) / num_tests* 100)

# Clean up
system('rm *.out')

exit(final_return_code)
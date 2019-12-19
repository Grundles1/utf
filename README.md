# utf
A basic unit test framework for C
  
The directory structure contains:  
  
`utf` - the the unit test framework, the code that implements the basic structure and functionality of the framework

`ut` - An example unit test collection

`uut` - An example of a directory of a unit under test 

`test_toplevel.c` - The top level script of the sample unit test that exercises the unit test framework

`makefile` - the makefile to buile the sample unit test using the the unit test framework


# to build and run

`make`

# to launch in lldb debugger

`make debug`

# to use with gcov to get coverage metrics on units under test

forthcoming
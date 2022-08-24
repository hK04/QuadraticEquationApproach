#the compiler
CC = g++
 
#flags:
CFLAGS  = -g -Wall -Wextra -Wpedantic -Wfloat-equal -Werror
 
#sources of input
SOURCES = main.cpp equation.cpp unit_tests.cpp

#sources of output
EXECUTABLE = main

all:
	$(CC) $(SOURCES) $(CFLAGS) -DDebugMode=0 -MD -o $(EXECUTABLE) -lm
debug:
	$(CC) $(SOURCES) $(CFLAGS) -DDebugMode=1 -MD -o $(EXECUTABLE) -lm

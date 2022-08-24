#the compiler
CC = gcc
 
#flags:
CFLAGS  = -g -Wall
 
#sources of input
SOURCES=main.cpp equation.cpp unit_tests.cpp

#sources of output
EXECUTABLE=main.o
all: 
	$(CC) $(SOURCES) $(CFLAGS) -DDebugMode=0 -o $(EXECUTABLE) -lm
debug:
	$(CC) $(SOURCES) $(CFLAGS) -DDebugMode=1 -o $(EXECUTABLE) -lm
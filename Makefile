# Variables
CC = g++
CFLAGS = -Wall -g -std=c++20

all: say_hello main

say_hello:
	@echo "Started the compilation of project..."

# Linking
main: main.o Plugboard.o Reflector.o Rotor.o
	${CC} ${CFLAGS} -o main main.o Plugboard.o Reflector.o Rotor.o

#Compilation + assembly
main.o: main.cpp Plugboard.h Reflector.h Rotor.h
	${CC} ${CFLAGS} -c main.cpp

Plugboard.o: Plugboard.h

Reflector.o: Reflector.h

Rotor.o: Rotor.h 

# Cleaning
clean:
	@echo "Cleaning up..."
	rm -r *.o
	rm -r main

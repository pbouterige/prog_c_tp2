all:
	gcc -o main lagrange.c  -g -Wall -Wpedantic -Wextra
	./main
all:
	gcc -o main main.c  -g -Wall -Wpedantic -Wextra -lm
	./main
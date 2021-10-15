all:
	gcc -o main newton.c  -g -Wall -Wpedantic -Wextra -lm
	./main
.PHONY:clean
CC =gcc
RM = rm

all: foo.o main.o
	$(CC) $^ -o $@
ma: foo.o main.o
	$(CC) $^ -o $@
main.o: main.c
	$(CC) -c $^ -o $@
foo.o: foo.c
	$(CC) -c $^ -o $@
clean:
	$(RM) main.o foo.o ma all

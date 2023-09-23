CC=gcc
CFLAGS= -Wall -Werror -Wextra
BD = ../build/

all: build_db

build_db: modules_db.o shared.o
	$(CC) $(CFLAGS) modules_db.o shared.o -o $(BD)Quest_1

shared.o: shared.c
	$(CC) $(CFLAGS) -c shared.c

clean:
	rm -rf *.o $(BD)Quest_1

rebuild: clean all

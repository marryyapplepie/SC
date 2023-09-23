CC=gcc
CFLAGS= -Wall -Werror -Wextra
BD = ../build/

all: cipher

cipher: cipher.o menu.o
	$(CC) $(CFLAGS) cipher.o menu.o -o $(BD)cipher

menu.o: menu.c
	$(CC) $(CFLAGS) -c menu.c

clean:
	rm -rf *.o $(BD)cipher

rebuild: clean all

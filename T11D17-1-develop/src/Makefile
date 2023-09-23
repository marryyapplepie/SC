CC=gcc
CFLAGS= -Wall -Werror -Wextra
BD = ../build/

all: door_struct list_test

door_struct: dmanager_module.o
	$(CC) $(CFLAGS) dmanager_module.o -o $(BD)Quest_1

dmanager_module.o: dmanager_module.c
	$(CC) $(CFLAGS) -c dmanager_module.c

list_test: list_test.o list.o 
	$(CC) $(CFLAGS) list_test.o list.o -o $(BD)Quest_2

list_test.o: list_test.c 
	$(CC) $(CFLAGS) -c -DTEST list_test.c

list.o: list.c
	$(CC) $(CFLAGS) -c list.c

clean:
	rm -rf *.o $(BD)Quest_1

rebuild: clean all
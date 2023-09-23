CC=gcc
CFLAGS= -Wall -Werror -Wextra
BD = ../build/

all: strlen_tests strcmp_tests strcpy_tests strcat_tests

strlen_tests: s21_string_test_strlen.o s21_string.o
	$(CC) $(CFLAGS) s21_string_test.o s21_string.o -o $(BD)Quest_1

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c 

s21_string_test_strlen.o: s21_string_test.c
	$(CC) $(CFLAGS) -c -DQ1 s21_string_test.c 

strcmp_tests: s21_string_test_strcmp.o s21_string.o
	$(CC) $(CFLAGS)  s21_string_test.o s21_string.o -o $(BD)Quest_2

s21_string_test_strcmp.o: s21_string_test.c
	$(CC) $(CFLAGS) -c -DQ2 s21_string_test.c

strcpy_tests: s21_string_test_strcpy.o s21_string.o
	$(CC) $(CFLAGS)  s21_string_test.o s21_string.o -o $(BD)Quest_3

s21_string_test_strcpy.o: s21_string_test.c
	$(CC) $(CFLAGS) -c -DQ3 s21_string_test.c

strcat_tests: s21_string_test_strcat.o s21_string.o
	$(CC) $(CFLAGS) s21_string_test.o s21_string.o -o $(BD)Quest_4

s21_string_test_strcat.o: s21_string_test.c
	$(CC) $(CFLAGS) -c -DQ4 s21_string_test.c


clean: 
	rm -rf *.o $(BD)Quest_1 $(BD)Quest_2 $(BD)Quest_3
 
rebuild: clean all

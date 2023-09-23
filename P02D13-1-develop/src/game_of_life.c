#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BOARD_HEIGHT 25
#define BOARD_WIDTH 80

int input_stat(int arr[BOARD_HEIGHT][BOARD_WIDTH]);
void print_stat(int arr[BOARD_HEIGHT][BOARD_WIDTH]);
void copy(int arr[BOARD_HEIGHT][BOARD_WIDTH], int arr_copy[BOARD_HEIGHT][BOARD_WIDTH]);
void life(int arr[BOARD_HEIGHT][BOARD_WIDTH]);
int count_neighbors(int n, int m, int arr[BOARD_HEIGHT][BOARD_WIDTH]);

int main() {
    int arr[BOARD_HEIGHT][BOARD_WIDTH];
    initscr();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    noecho();
    if (input_stat(arr) == 0) {
        FILE* f = freopen("/dev/tty", "r", stdin);
        int arr_copy[BOARD_HEIGHT][BOARD_WIDTH];
        copy(arr, arr_copy);
        int t = 250000;
        while (1) {
            clear();
            int c = getch();
            if (c == 'q') break;
            if (c == '+' && t < 500000) t -= 10000;
            if (c == '-' && t > 10000) t += 10000;
            life(arr_copy);
            copy(arr_copy, arr);
            print_stat(arr_copy);
            refresh();
            usleep(t);
        }
        fclose(f);
    } else
        printw("n/a\n");
    endwin();
    return 0;
}

int input_stat(int arr[BOARD_HEIGHT][BOARD_WIDTH]) {
    int h = 0;
    int w = 0;
    int flag = 0;
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (scanf("%d", &arr[i][j]) != 1) flag = 1;
            w++;
        }
        if (w != BOARD_WIDTH) flag = 1;
        w = 0;
        h++;
    }
    if (h != BOARD_HEIGHT) flag = 1;
    return flag;
}

void print_stat(int arr[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (arr[i][j] == 0) {
                printw(" ");
            } else if (arr[i][j] == 1) {
                printw("x");
            }
        }
        printw("\n");
    }

    refresh();
}

void copy(int arr[BOARD_HEIGHT][BOARD_WIDTH], int arr_copy[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            arr_copy[i][j] = arr[i][j];
        }
    }
}

void life(int arr[BOARD_HEIGHT][BOARD_WIDTH]) {
    int arr_copy[BOARD_HEIGHT][BOARD_WIDTH];

    copy(arr, arr_copy);

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            int neighbors = count_neighbors(i, j, arr_copy);
            if (arr_copy[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                arr[i][j] = 0;
            } else if (arr_copy[i][j] == 0 && neighbors == 3) {
                arr[i][j] = 1;
            }
        }
    }
}

int count_neighbors(int n, int m, int arr[BOARD_HEIGHT][BOARD_WIDTH]) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i != 0 || j != 0) {
                int ni = (n + i + BOARD_HEIGHT) % BOARD_HEIGHT;
                int mj = (m + j + BOARD_WIDTH) % BOARD_WIDTH;
                count += arr[ni][mj];
            }
        }
    }

    return count;
}
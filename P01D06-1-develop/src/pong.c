#include <stdio.h>

// Размеры игрового поля и объектов
#define FIELD_WIDTH 80
#define FIELD_HEIGHT 25
#define RACKET_SIZE 3
#define BALL_SIZE 1

void displayField();
int moveRackets1(int player1Y, char key);
int moveRackets2(int player2Y, char key);
int playerAdd(int playerY);
int playerSub(int playerY);
int moveBallX(int ballX, int ballSpeedX);
int moveBallY(int ballY, int ballSpeedY);
int topAndBottomLogic(int ballY, int ballSpeedY);
int rocketsAndBallLogic(int player1Y, int player2Y, int ballSpeedX, int ballX, int ballY);

int main() {
    // Начальное положение мяча и скорость
    int ballX, ballY;
    int ballSpeedX, ballSpeedY;

    // Инициализация начальных значений переменных
    ballX = FIELD_WIDTH / 2;
    ballY = FIELD_HEIGHT / 2;
    // Начальная скорость мяча по горизонтали и вертикали
    ballSpeedX = 1;
    ballSpeedY = 1;
    // Начальное положение ракеток игроков
    int player1Y, player2Y;

    // Размещение ракеток
    player1Y = FIELD_HEIGHT / 2 - RACKET_SIZE / 2;
    player2Y = FIELD_HEIGHT / 2 - RACKET_SIZE / 2;

    int scorePlayer1 = 0;
    int scorePlayer2 = 0;
    // Флаг состояния игры (1 - игра продолжается, 0 - игра завершена)
    int gameInProgress = 1;

    // Главный игровой цикл
    while (gameInProgress == 1) {
        displayField(player1Y, player2Y, ballX, ballY, scorePlayer1, scorePlayer2);

        ballX = moveBallX(ballX, ballSpeedX);
        ballY = moveBallY(ballY, ballSpeedY);
        ballSpeedY = topAndBottomLogic(ballY, ballSpeedY);
        ballSpeedX = rocketsAndBallLogic(player1Y, player2Y, ballSpeedX, ballX, ballY);

        char key = getchar();

        if (key == 'a' || key == 'z') {
            player1Y = moveRackets1(player1Y, key);
        }
        if (key == 'k' || key == 'm') {
            player2Y = moveRackets2(player2Y, key);
        }
        // Логика забивания голов и подсчет очков
        if (ballX == 0) {
            scorePlayer2++;
            ballX = FIELD_WIDTH / 2;
            ballY = FIELD_HEIGHT / 2;
            ballSpeedX = 1;
            ballSpeedY = 1;
        }

        if (ballX == FIELD_WIDTH - 1) {
            scorePlayer1++;
            ballX = FIELD_WIDTH / 2;
            ballY = FIELD_HEIGHT / 2;
            ballSpeedX = -1;
            ballSpeedY = -1;
        }

        if (scorePlayer1 >= 21 || scorePlayer2 >= 21) {
            gameInProgress = 0;
        }

        // Вывести сообщение о победителе и завершить игру
        if (scorePlayer1 == 21) {
            printf("Player 1 wins!\n");
        } else if (scorePlayer2 == 21) {
            printf("Player 2 wins!\n");
        }
    }

    return 0;
}

// Процедура для отображения поля
void displayField(int player1Y, int player2Y, int ballX, int ballY, int scorePlayer1, int scorePlayer2) {
    // Очистить экран (вывести много символов новой строки)
    for (int i = 0; i < 100; i++) {
        printf("\n");
    }

    // Отобразить верхние границы поля
    for (int i = 0; i < FIELD_WIDTH; i++) {
        printf("-");
    }
    printf("\n");

    // Отобразить игровое поле и объекты
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            if (j == 0 || j == FIELD_WIDTH - 1) {
                printf("|");
            } else if (i == ballY && j == ballX) {
                printf("0");
            } else if (i >= player1Y && i < player1Y + RACKET_SIZE && j == 1) {
                printf("#");
            } else if (i >= player2Y && i < player2Y + RACKET_SIZE && j == FIELD_WIDTH - 2) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Отобразить нижние границы поля
    for (int i = 0; i < FIELD_WIDTH; i++) {
        printf("-");
    }
    printf("\n");
    // Отобразить счет игроков
    printf("Player 1: %d   Player 2: %d\n", scorePlayer1, scorePlayer2);
}

//Функция для управления ракетками
int moveRackets1(int player1Y, char key) {
    switch (key) {
        case 'a':
            if (player1Y > 0) {
                player1Y = playerSub(player1Y);
            }
            break;
        case 'z':
            if (player1Y < FIELD_HEIGHT - RACKET_SIZE) {
                player1Y = playerAdd(player1Y);
            }
            break;
        default:
            break;
    }
    return player1Y;
}

int moveRackets2(int player2Y, char key) {
    switch (key) {
        case 'k':
            if (player2Y > 0) {
                player2Y = playerSub(player2Y);
            }
            break;
        case 'm':
            if (player2Y < FIELD_HEIGHT - RACKET_SIZE) {
                player2Y = playerAdd(player2Y);
            }
            break;
        case ' ':
            break;
        default:
            break;
    }
    return player2Y;
}

int playerAdd(int playerY) {
    playerY++;
    return playerY;
}

int playerSub(int playerY) {
    playerY--;
    return playerY;
}
//Двигаем мяч по оси Х
int moveBallX(int ballX, int ballSpeedX) {
    ballX += ballSpeedX;
    return ballX;
}
//Двигаем мяч по оси Y
int moveBallY(int ballY, int ballSpeedY) {
    ballY += ballSpeedY;
    return ballY;
}
//При столкновении со стенкой - меняем направление
int topAndBottomLogic(int ballY, int ballSpeedY) {
    if (ballY <= 0 || ballY >= FIELD_HEIGHT - BALL_SIZE) {
        ballSpeedY = -ballSpeedY;
    }
    return ballSpeedY;
}
//При столкновении с ракеткой - меняем направление
int rocketsAndBallLogic(int player1Y, int player2Y, int ballSpeedX, int ballX, int ballY) {
    if (ballX == 2 && (ballY >= player1Y && ballY < player1Y + RACKET_SIZE)) {
        ballSpeedX = -ballSpeedX;
    }
    if (ballX == FIELD_WIDTH - 3 && (ballY >= player2Y && ballY < player2Y + RACKET_SIZE)) {
        ballSpeedX = -ballSpeedX;
    }
    return ballSpeedX;
}

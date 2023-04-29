//
// Created by Piquionne Andy on 30/04/2023.
//

/*

#include <stdio.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 7

void display_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
}

bool check_winner(char board[ROWS][COLS], char player) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player && board[i][j+3] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player && board[i+3][j] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player && board[i+3][j+3] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 3; j < COLS; j++) {
            if (board[i][j] == player && board[i+1][j-1] == player && board[i+2][j-2] == player && board[i+3][j-3] == player) {
                return true;
            }
        }
    }

    return false;
}


bool place_piece(char board[ROWS][COLS], int col, char player) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = player;
            return true;
        }
    }
    return false;
}

int main() {
    char board[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    int col;
    char player;

    for (int turn = 0; turn < ROWS * COLS; turn++) {
        display_board(board);
        player = (turn % 2 == 0) ? 'X' : 'O';

        do {
            printf("Player %c, choose a column (0-6): ", player);
            scanf("%d", &col);
        } while (col < 0 || col >= COLS ||
                 !place_piece(board, col, player));

        if (check_winner(board, player)) {
            display_board(board);
            printf("Player %c wins!\n", player);
            break;
        } else if (turn == ROWS * COLS - 1) {
            display_board(board);
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}
*/

//Avec ordinateur

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 7

void display_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
}

bool check_winner(char board[ROWS][COLS], char player) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player && board[i][j+3] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player && board[i+3][j] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player && board[i+3][j+3] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 3; j < COLS; j++) {
            if (board[i][j] == player && board[i+1][j-1] == player && board[i+2][j-2] == player && board[i+3][j-3] == player) {
                return true;
            }
        }
    }

    return false;
}



bool place_piece(char board[ROWS][COLS], int col, char player) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = player;
            return true;
        }
    }
    return false;
}


int computer_move(char board[ROWS][COLS]) {
    int col;
    do {
        col = rand() % COLS;
    } while (!place_piece(board, col, 'O'));
    return col;
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    int col;
    char player;

    for (int turn = 0; turn < ROWS * COLS; turn++) {
        display_board(board);

        if (turn % 2 == 0) { // Player's turn
            player = 'X';
            do {
                printf("Player %c, choose a column (0-6): ", player);
                scanf("%d", &col);
            } while (col < 0 || col >= COLS || !place_piece(board, col, player));
        } else { // Computer's turn
            player = 'O';
            printf("Computer is choosing a column...\n");
            col = computer_move(board);
            printf("Computer chose column %d\n", col);
        }

        if (check_winner(board, player)) {
            display_board(board);
            printf("Player %c wins!\n", player);
            break;
        } else if (turn == ROWS * COLS - 1) {
            display_board(board);
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}

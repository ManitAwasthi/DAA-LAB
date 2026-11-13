#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX];
int n;

int isSafe(int row, int col) {

    for (int i = 0; i < row; i++) {

        if (board[i] == col ||
            abs(board[i] - col) == abs(i - row))

            return 0;
    }

    return 1;
}

int solve(int row) {

    if (row == n)
        return 1;

    for (int col = 0; col < n; col++) {

        if (isSafe(row, col)) {

            board[row] = col;

            if (solve(row + 1))
                return 1;
        }
    }

    return 0;
}

void printBoard() {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }

        printf("\n");
    }
}

int main() {

    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (solve(0)) {

        printf("\nSolution:\n");
        printBoard();

    } else {

        printf("No solution exists.\n");
    }

    return 0;
}

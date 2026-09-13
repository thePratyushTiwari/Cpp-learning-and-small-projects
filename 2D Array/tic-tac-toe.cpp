#include <iostream>
#include <ctime>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | "
         << board[0][1] << " | "
         << board[0][2] << endl;

    cout << "---|---|---\n";

    cout << " " << board[1][0] << " | "
         << board[1][1] << " | "
         << board[1][2] << endl;

    cout << "---|---|---\n";

    cout << " " << board[2][0] << " | "
         << board[2][1] << " | "
         << board[2][2] << endl;
}

bool checkWin(char player) {

    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Diagonal
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

bool isDraw() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

void playerMove() {

    int move;

    while (true) {

        cout << "\nEnter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid move!\n";
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' ||
            board[row][col] == 'O') {

            cout << "Position already occupied!\n";
            continue;
        }

        board[row][col] = 'X';
        break;
    }
}

void computerMove() {

    int move;
    int row, col;

    // Generate a pseudo-random number using current time
    move = (time(0) % 9) + 1;

    // Keep looking until an empty position is found
    while (true) {

        row = (move - 1) / 3;
        col = (move - 1) % 3;

        if (board[row][col] != 'X' &&
            board[row][col] != 'O') {

            board[row][col] = 'O';

            cout << "\nComputer chose: " << move << endl;
            return;
        }

        // Try the next position
        move++;

        if (move > 9)
            move = 1;
    }
}

int main() {

    cout << "====================\n";
    cout << "    TIC-TAC-TOE\n";
    cout << "====================\n";

    cout << "\nYou = X";
    cout << "\nComputer = O\n";

    displayBoard();

    while (true) {

        // Player's turn
        playerMove();
        displayBoard();

        if (checkWin('X')) {
            cout << "\nYou WIN!\n";
            break;
        }

        if (isDraw()) {
            cout << "\nIt's a DRAW!\n";
            break;
        }

        // Computer's turn
        computerMove();
        displayBoard();

        if (checkWin('O')) {
            cout << "\nComputer WINS!\n";
            break;
        }

        if (isDraw()) {
            cout << "\nIt's a DRAW!\n";
            break;
        }
    }

    return 0;
}

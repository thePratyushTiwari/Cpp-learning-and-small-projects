#include<bits/stdc++.h>
using namespace std;

void printSudoku(int sudoku[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << sudoku[i][j] << ((j+1)%3==0 ? "   " : " ");
        }
        cout << ((i+1)%3==0 ? "\n\n" : "\n");
    }
}

bool isSafe(int sudoku[9][9], int row, int col, int digit) {
    
    //checking vertically
    for(int i=0; i <=8; i++) {
        if(sudoku[i][col]==digit) return false;
    }
    
    //checking horizontal
    for(int i=0; i <=8; i++ ) {
        if(sudoku[row][i]==digit) return false;
    }

    //3x3 grid checking
    int startRow = row - (row%3);
    int startCol = col - (col%3);
    for(int i=startRow; i<= startRow+2; i++) {
        for(int j=startCol; j<=startCol+2; j++) {
            if(sudoku[i][j] == digit) return false;
        }
    }
    return true;
}

bool sudokuSolver(int sudoku[9][9], int row=0, int col=0) {
    //Base Case --> row = 9 (complete sudoku solved)
    if( row==9 ) {
        printSudoku( sudoku );
        return true;
    }
    int nextRow = row;
    int nextCol = col + 1;
    if(col+1 == 9) {
        nextRow = row+1;
        nextCol = 0;
    }
    
    if(sudoku[row][col]!=0) return sudokuSolver(sudoku,nextRow, nextCol);

    for( int digit=1; digit <=9; digit++ ) {
        if(isSafe(sudoku, row, col, digit)) {
            sudoku[row][col] = digit;
            if(sudokuSolver(sudoku, nextRow, nextCol)) return true;
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int sudoku[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
                        {4, 9, 0, 1, 5, 7, 0, 0, 2},
                        {0, 0, 3, 0, 0, 4, 1, 9, 0},
                        {1, 8, 5, 0, 6, 0, 0, 2, 0},
                        {0, 0, 0, 0, 2, 0, 0, 6, 0},
                        {9, 6, 0, 4, 0, 5, 3, 0, 0},
                        {0, 3, 0, 0, 7, 2, 0, 0, 4},
                        {0, 4, 9, 0, 3, 0, 0, 5, 7},
                        {8, 2, 7, 0, 0, 9, 0, 1, 3}};
    cout << "Given Sudoku:\n";
    printSudoku(sudoku);
    cout << "\nSolved Sudoku:\n";
    sudokuSolver(sudoku);
    return 0;
}

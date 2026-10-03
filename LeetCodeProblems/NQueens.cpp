#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(vector<string> board, int row, int col) {
        int n = board.size();
        //horizontal checking
        for(int i=0; i < n; i++) if(board[row][i] == 'Q') return false;

        //vertical checking
        for(int i=0; i < row; i++) if(board[i][col] == 'Q') return false;

        //diagonal left
        for(int i=row, j=col; i >= 0 && j >= 0; i--, j--) if(board[i][j] == 'Q') return false;

        //diagonal right
        for(int i=row, j=col; i >= 0 && j < n; i--, j++) if(board[i][j] == 'Q') return false;

        return true;
    }

    void NQueens(vector<vector<string>>& board, int row, vector<string> currBoard) {
        int n = currBoard.size();
        if( row==n ) {
            board.push_back(currBoard);
            return;
        }

        for(int i=0; i < n; i++) {
            if(isSafe(currBoard, row, i)) {
                string S = currBoard[row];
                currBoard[row][i] = 'Q';
                NQueens(board, row+1, currBoard);
                currBoard[row] =S;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board;
        vector<string> currBoard(n, string(n, '.'));
        NQueens(board,0,currBoard);
        return board;
    }
};

void printBoard(vector<vector<string>> board) {
    int n = board.size();
    int m = board[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k=0; k < m; k++) {
                cout << board[i][j][k] << ' ';
            }
            cout << '\n';
        }
        cout << "\n";
    }
}

int main()
{
    cout << "--> This program give you number of ways and the number of ways you can place N queen on an NxN chess board without any queen threating other queen(s).\n";
    int n;
    cout << "\nEnter grid size: ";
    cin >> n;
    Solution ans;
    vector<vector<string>> board = ans.solveNQueens(n);
    cout << "Number of ways to place queen on board: " << board.size() << "\n\n";
    if(!board.empty()) printBoard(board);
    return 0;
}

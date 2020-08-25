#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
    bool solve(vector<vector<char>>& board, int i, int j) {
        if (j == 9)i++, j = 0;
        if (i == 9)return true;        
        if (board[i][j] != '.')solve(board,i, j + 1);
        else {
            for (char c = '1'; c <= '9'; c++) {
                if (!check(board, i, j, c))continue;                
                else board[i][j] = c;
                if (solve(board, i, j + 1))return true;
                else  board[i][j] = '.';
            }
            return false;
        }
    }
    bool check(vector<vector<char>>& board, int i, int j,char c) {
        for (int k = 0; k < 9; k++)
            if (c==board[k][j])return false;
        for (int k = 0; k < 9; k++)
            if (c == board[i][k])return false;
        int r0 = i / 3*3, c0 = j / 3*3;
        for (int m = r0; m < r0 + 3; m++)
            for (int n = c0; n < c0 + 3; n++)
                if (c == board[m][n])return false;
        return true;
    }
};
int main() {
    Solution sol;
    vector<vector<char>> board(9,vector<char>(9));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            board[i][j]='.';
    board = { {'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'} };
    sol.solveSudoku(board);
    for (auto i : board) {
        for (auto j : i)
            cout << j << "   ";
        cout << endl;
    }
}


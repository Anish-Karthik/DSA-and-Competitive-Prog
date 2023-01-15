#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        unordered_set<char> b;
        vector<unordered_set<char>> rows(9,b),cols(9,b),squares(9,b);
        fill(board,0,0,rows,cols,squares);
        cout<<"{";
        for(auto x: board) {
            cout<<"{";
            for(char c: x)
            {
                cout<<'"'<<c<<'"'<<",";
            }
            cout<<"}"<<",\n";
        }
        cout<<"}";
    }

    bool fill(vector<vector<char>>& board,int row,int col,vector<unordered_set<char>> &rows,vector<unordered_set<char>> &cols, vector<unordered_set<char>> &squares) {
         
        if(row == 9) return true;
        if(col == 9) return fill(board,row+1,0,rows,cols,squares);
        

        if(board[row][col]=='.') {
            for(char c='1'; c-'1'<9; c++){
                if(isValid(board,row,col,c)) {
                    board[row][col] = c;
                    if(fill(board,row,col+1,rows,cols,squares)) return true;
                    else board[row][col] = '.';
                }
            }
            return false; 
        }
        return fill(board,row,col+1,rows,cols,squares);
    }
    bool isValid(vector<vector<char>>& board,int row, int col,char c) {
        for(int i = 0; i< 9; i++) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> vec1={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char>> vec={
        {'.','.','.','.','.','8','.','.','.'},
        {'.','5','.','1','9','5','.','.','.'},
        {'.','.','.','5','7','3','.','.','9'},
        {'.','1','.','.','9','.','.','8','.'},
        {'9','2','8','7','.','.','5','.','6'},
        {'7','.','.','.','.','5','4','.','.'},
        {'6','.','.','.','.','1','.','4','.'},
        {'8','3','.','.','6','.','2','.','.'},
        {'.','.','.','.','8','.','6','.','1'}
    };
    Solution obj;
    obj.solveSudoku(vec1);
    cout<<"[";
    for(auto x: vec1) {
        cout<<"[";
        for(char c: x)
        {
            cout<<'"'<<c<<'"'<<",";
        }
        cout<<"]"<<",\n";
    }
    cout<<"]";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        unordered_set<char> b;
        vector<unordered_set<char>> rows(9,b),cols(9,b),squares(9,b);
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    char c = board[i][j];
                    cols[i].insert(c);
                }
                if (board[j][i] != '.') {
                    char c = board[j][i];
                    rows[i].insert(c);
                }
                if (board[3*(i/3)+j/3][3*(i%3)+j%3]!='.'){
                    char c= board[3*(i/3)+j/3][3*(i%3)+j%3];
                    squares[i].insert(c);
                }
            }
        }

        fill(board,0,0,rows,cols,squares);
    }

private:
    bool fill(vector<vector<char>>& board,int row,int col,
        vector<unordered_set<char>> &rows,vector<unordered_set<char>> &cols, vector<unordered_set<char>> &squares) {
         
        if(row == 9) return true;
        if(col == 9) return fill(board,row+1,0,rows,cols,squares);
        

        if(board[row][col]=='.') {
            for(char c='1'; c-'1'<9; c++){
                if(isValid(board,row,col,c,rows,cols,squares)) {
                    board[row][col] = c;
                    rows[col].insert(c);
                    cols[row].insert(c);
                    squares[2*(row/3)+((row/3)+(col/3))].insert(c);
                    if(fill(board,row,col+1,rows,cols,squares)) return true;
                    else{
                        rows[col].erase(c);
                        cols[row].erase(c);
                        squares[2*(row/3)+((row/3)+(col/3))].erase(c);
                        board[row][col] = '.';
                    } 
                }
            }
            return false; 
        }
        return fill(board,row,col+1,rows,cols,squares);
    }


private:
    bool isValid(vector<vector<char>>& board,int row, int col,char c) {
        for(int i = 0; i< 9; i++) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
        }
        return true;
    }
private:
    bool isValid(vector<vector<char>>& board,int row, int col,char c,
        vector<unordered_set<char>> &rows,
        vector<unordered_set<char>> &cols,
        vector<unordered_set<char>> &squares) {
        if (rows[col].find(c)!=rows[col].end()) return false;
        if (cols[row].find(c)!=cols[row].end()) return false;
        if (squares[2*(row/3)+((row/3)+(col/3))].find(c)!=
            squares[2*(row/3)+((row/3)+(col/3))].end()) return false;
        return true;
    }
};

int main()
{
    vector<vector<char>> vec={
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
    Solution obj;
    obj.solveSudoku(vec);
    cout<<"[";
    for(auto x: vec) {
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
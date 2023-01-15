#include<bits/stdc++.h>
using namespace std;
class NQueens {
	/*  Approach 1
		T.C: O(n! * n)
		S.C: O(n^2)
	*/
private:
	//O(n)
	bool isSafe(vector<string> &board,int n,int m,int size) {
		for(int i=0;i<m;i++) {
			if (board[n][i]=='Q') return false;
		}
		for(int i=n,j=m;i>=0 && j>=0;i--,j--) {
			if (board[i][j]=='Q') return false;
		}
		for(int i=n,j=m;i<size && j>=0; i++,j--) {
			if (board[i][j]=='Q') return false;
		}
		return true;
	}
public:
	void nQueens(int n,int col, vector<string> &board, vector<vector<string>> &ans) {

		if (col >= n){
			ans.push_back(board);
			return;
		}

		for(int i =0;i<n;i++ ){
			if(board[i][col] != 'Q' && isSafe(board,i,col,n)) {
				board[i][col] = 'Q';
				nQueens(n,col+1,board,ans);
				board[i][col] = '.';
			}
		}
	}

	/*  Approach 2
		T.C: O(n!)
		S.C: O(n^2)
	*/
private:
	//O(1)
	void setReset(vector<bool> &leftRow,vector<bool> &upDiag, vector<bool> &lowDiag,
		int i, int j, int n) {
		leftRow[i] = !leftRow[i];
		upDiag[n-1+i+j] = !upDiag[n-1+i+j];
		lowDiag[i+j] = !lowDiag[i+j];
	}
public:
	void nQueens(int n,int col, vector<string> &board, vector<vector<string>> &ans,
		vector<bool> &leftRow,vector<bool> &upDiag, vector<bool> &lowDiag) {

		if(col >= n){
			ans.push_back(board);
			return;
		}

		for(int row = 0; row < n; row++) {
			if(board[row][col] != 'Q' && !leftRow[row] && !upDiag[n-1+row+col]
				&& !lowDiag[row+col]) {
				setReset(leftRow,upDiag,lowDiag,row,col,n);
				board[row][col] = 'Q';
				nQueens(n,col+1,board,ans);
				board[row][col] = '.';
				setReset(leftRow,upDiag,lowDiag,row,col,n);
			}
		}
	}
};


int main()
{
	int n = 4;
	string row(n,'.');
	vector<vector<string>> ans,res;
	vector<string> board(n,row);
	NQueens obj;
	obj.nQueens(n,0,board,ans);
	cout<<"approach 1, none optimized\n";
	cout<<"combinations for board size "<<n<<" is "<<ans.size()<<endl;
	for(auto board: ans) {
		for(string row: board)
			cout<<row<<endl;
		cout<<endl;
	}
	vector<bool> leftRow(n,false);
	vector<bool> upDiag(2*n-1,false);
	vector<bool> lowDiag(2*n-1,false);
	cout<<"---------------------------------"<<endl;
	obj.nQueens(n,0,board,res,leftRow,upDiag,lowDiag);
	cout<<"approach 2, time optimized\n";
	cout<<"combinations for board size "<<n<<" is "<<res.size()<<endl;
	for(auto board: res) {
		for(string row: board)
			cout<<row<<endl;
		cout<<endl;
	}
    return 0;
}
class Solution {
public:
    void solve(vector<vector<string>>& ans, vector<string> &board, int row, int n)
    {
        if(row == n){
            ans.push_back(board);
            return ;
        }

        for(int i=0;i<n;i++){
            if(isSafe(board,row,i,n)){
                board[row][i] = 'Q';
                solve(ans,board,row+1,n);
                board[row][i] = '.';
            }
        }
    }

    bool isSafe(vector<string> &board, int row,int col, int n){
        for(int i=0;i<row;i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        for(int i=row,j=col;i>=0 && j<=n;i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>st(n,string(n, '.'));
        solve(ans,st,0,n);
        return ans;
    }
};

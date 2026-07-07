class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> hm;
        vector<string> board(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i].push_back('.');
            }
        }
        vector<int> leftD(2 * n - 1, 0);
        vector<int> rightD(2 * n - 1, 0);
        vector<int> col(n, 0);
        find(0, n, hm, col, leftD, rightD,board);
        return hm;
    }

private:
    void find(int row, int n, vector<vector<string>>& hm, vector<int>& col,
              vector<int>& leftD, vector<int>& rightD,vector<string>&board) {
        if (row == n) {
            hm.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (col[i] == 0 && leftD[n - 1 + row - i] == 0 &&
                rightD[row + i] == 0) {
                col[i] = 1;
                leftD[n - 1 + row - i] = 1;
                rightD[row + i] = 1;
                board[row][i] = 'Q';
                find(row + 1, n, hm, col, leftD, rightD,board);
                col[i] = 0;
                board[row][i] = '.';
                leftD[n - 1 + row - i] = 0;
                rightD[row + i] = 0;
            }
        }
    }
};










class Solution {
public:
    bool issafe(vector<string> &b,int row,int col,int n){

        for(int j=0;j<n;j++){
            if(b[row][j]=='Q')
                return false;
        }

        for(int i=0;i<n;i++){
            if(b[i][col]=='Q')
                return false;
        }

        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(b[i][j]=='Q')
                return false;
        }

        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(b[i][j]=='Q')
                return false;
        }

        return true;
    }

    void nQueens(vector<string> &board,int row,int n,
                 vector<vector<string>> &ans){

        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int j=0;j<n;j++){
            if(issafe(board,row,j,n)){
                board[row][j]='Q';
                nQueens(board,row+1,n,ans);
                board[row][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;

        nQueens(board,0,n,ans);

        return ans;
    }
};

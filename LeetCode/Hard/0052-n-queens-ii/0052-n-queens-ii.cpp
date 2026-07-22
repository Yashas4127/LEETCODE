class Solution {
public:
    int totalNQueens(int n) {
        int hm=0;
        vector<string>board(n,string(n,'.'));
        vector<int>leftD(2*n-1,0);
        vector<int>rightD(2*n-1,0);
        vector<int>col(n,0);

        slove(0,n,hm,leftD,rightD,col,board);
        return hm;
    }

    private:

    void slove(int row,int n, int &hm,vector<int>leftD,vector<int>rightD,vector<int>col,vector<string>board){
        if(row==n){
            hm++;
            return ;
        }

        for(int i=0;i<n;i++){
            if(col[i]==0 && leftD[n-1+i-row]==0 && rightD[i+row]==0){
                board[row][i]='Q';
                leftD[n-1+i-row]=1;
                rightD[i+row]=1;
                col[i]=1;
                slove(row+1,n,hm,leftD,rightD,col,board);
                board[row][i]='.';
                col[i]=0;
                leftD[n-1+i-row]=0;
                rightD[i+row]=0;


            }
        }
    }

};
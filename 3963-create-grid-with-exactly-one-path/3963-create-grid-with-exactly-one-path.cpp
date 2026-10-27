class Solution {
public:
    vector<string> createGrid(int m, int n) {
       vector<string> hm(m, string(n, ' '));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0 || i==m-1){
                    hm[i][j]='.';
                }
                else{
                    hm[i][j]='#';
                }
            }
        }
        return hm;
    }
};
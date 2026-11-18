class Solution {
public:
int help(int i,int j,string &t1, string &t2,vector<vector<int>>&dp){
      if (i < 0 || j < 0) {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
    if(t1[i]==t2[j]){
        return dp[i][j]=1+help(i-1,j-1,t1,t2,dp);
    }
    int nMi=help(i-1,j,t1,t2,dp);
    int nMj=help(i,j-1,t1,t2,dp);
    return dp[i][j]=max(nMi,nMj);
}
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return help(n1-1,n2-1,text1,text2,dp);
    }
};
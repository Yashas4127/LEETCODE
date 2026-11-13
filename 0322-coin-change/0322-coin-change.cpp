class Solution {
public:
    int help(int i, int a, vector<int>& c,vector<vector<int>>&dp) {
        if (a == 0)
            return 0;

        if (i == 0) {
            if (a % c[0] == 0)
                return a / c[0];

            return 1e9;
        }
        if(dp[i][a]!=-1) return dp[i][a];
        int nT = help(i - 1, a, c,dp);
        int T = 1e9;
        if (a >= c[i]) {
            T = 1 + help(i, a - c[i], c,dp);
        }
        return dp[i][a]=min(nT, T);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int hm= help(coins.size() - 1, amount, coins,dp);
        return hm>=1e9? -1:hm;
    }

};
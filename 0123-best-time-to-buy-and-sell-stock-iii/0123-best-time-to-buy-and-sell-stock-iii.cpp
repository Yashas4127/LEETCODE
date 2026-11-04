class Solution {
public:
    int help(int i, int n, vector<int>& p, int k, int buy,
             vector<vector<vector<int>>>& dp) {
        if (i == n)
            return 0;
        if (k == 2)
            return 0;
        if (dp[i][buy][k] != -1)
            return dp[i][buy][k];
        int profit = 0;
        if (buy) {
            profit = max(-p[i] + help(i + 1, n, p, k, 0, dp),
                         help(i + 1, n, p, k, 1, dp));
        } else {
            profit = max(p[i] + help(i + 1, n, p, k + 1, 1, dp),
                         help(i + 1, n, p, k, 0, dp));
        }
        return dp[i][buy][k] = profit;
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>>prev(2, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>>curr(2, vector<int>(3, 0));
            for (int buy = 0; buy <= 1; buy++) {
                for (int k = 0; k < 2; k++) {
                    int profit = 0;
                    if (buy) {
                        profit = max(-p[i] + prev[0][k],
                                     prev[1][k]);
                    } else {
                        profit = max(p[i] + prev[1][k+1],
                                    prev[0][k]);
                    }
                    curr[buy][k] = profit;
                }
                
            }
            prev=curr;
        }
        return prev[1][0];
    }
};
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
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int k = 0; k < 2; k++) {
                    int profit = 0;
                    if (buy) {
                        profit = max(-p[i] + dp[i+1][0][k],
                                     dp[i+1][1][k]);
                    } else {
                        profit = max(p[i] + dp[i+1][1][k+1],
                                    dp[i+1][0][k]);
                    }
                    dp[i][buy][k] = profit;
                }
            }
        }
        return dp[0][1][0];
    }
};
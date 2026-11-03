class Solution {
public:
    int help(int i, int buy, int n, vector<int>& a, vector<vector<int>>& dp) {
        if (i == n)
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if (buy) {
            profit =
                max(-a[i] + help(i + 1, 0, n, a, dp), help(i + 1, 1, n, a, dp));
        } else {
            profit =
                max(a[i] + help(i + 1, 1, n, a, dp), help(i + 1, 0, n, a, dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        dp[n][0] = dp[n][1] = 0;
        vector<int>front(2,0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int>curr(2,0);
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-a[i] + front[0],
                                 front[1]);
                } else {
                    profit = max(a[i] + front[1],
                                front[0]);
                }
                 curr[buy] = profit;
            }
            front=curr;
        }
        return front[1];
    }
};
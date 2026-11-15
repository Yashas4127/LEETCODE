class Solution {
public:
    int help(int i, int amt, vector<int>& coins, vector<vector<int>>& dp) {
        if (amt == 0)
            return 1;
        if (i == 0) {
            if (amt % coins[0] == 0)
                return 1;
            return 0;
        }
        if (dp[i][amt] != -1)
            return dp[i][amt];
        int nP = help(i - 1, amt, coins, dp);
        int P = 0;
        if (amt >= coins[i]) {
            P = help(i, amt - coins[i], coins, dp);
        }

        return dp[i][amt] = nP + P;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return help(n - 1, amount, coins, dp);
    }
};
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<unsigned long long>> dp(
            n, vector<unsigned long long>(amount + 1, 0)
        );

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int amt = 0; amt <= amount; amt++) {
            if (amt % coins[0] == 0) {
                dp[0][amt] = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int amt = 0; amt <= amount; amt++) {

                auto nP = dp[i - 1][amt];
                unsigned long long P = 0;

                if (amt >= coins[i]) {
                    P = dp[i][amt - coins[i]];
                }

                dp[i][amt] = nP + P;
            }
        }

        return dp[n - 1][amount];
    }
};
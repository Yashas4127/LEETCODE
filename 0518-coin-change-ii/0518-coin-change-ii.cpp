class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<unsigned long long> prev(amount + 1, 0);

        prev[0] = 1;

        // Base case
        for (int amt = 0; amt <= amount; amt++) {
            if (amt % coins[0] == 0) {
                prev[amt] = 1;
            }
        }

        // DP
        for (int i = 1; i < n; i++) {

            vector<unsigned long long> curr(amount + 1, 0);

            for (int amt = 0; amt <= amount; amt++) {

                auto nP = prev[amt];

                unsigned long long P = 0;

                if (amt >= coins[i]) {
                    P = curr[amt - coins[i]];
                }

                curr[amt] = nP + P;
            }

            prev = curr;
        }

        return prev[amount];
    }
};
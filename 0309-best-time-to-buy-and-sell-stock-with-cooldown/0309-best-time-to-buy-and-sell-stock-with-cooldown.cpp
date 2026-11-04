class Solution {
public:
    int maxProfit(vector<int>& p) {

        int n = p.size();

        vector<int> prev(2, 0);
        vector<int> prev2(2, 0);

        for (int i = n - 1; i >= 0; i--) {

            vector<int> curr(2, 0);

            for (int buy = 1; buy >= 0; buy--) {

                if (buy == 1) {
                    curr[buy] = max(
                        -p[i] + prev[0],
                        prev[1]
                    );
                }
                else {
                    curr[buy] = max(
                        p[i] + prev2[1],
                        prev[0]
                    );
                }
            }

            prev2 = prev;
            prev = curr;
        }

        return prev[1];
    }
};
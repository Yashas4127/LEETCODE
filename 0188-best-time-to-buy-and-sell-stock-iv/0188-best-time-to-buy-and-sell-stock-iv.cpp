class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
         int n = p.size();
        vector<vector<int>>prev(2, vector<int>(k+1, 0));
        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>>curr(2, vector<int>(k+1, 0));
            for (int buy = 0; buy <= 1; buy++) {
                for (int j = 0; j < k; j++) {
                    int profit = 0;
                    if (buy) {
                        profit = max(-p[i] + prev[0][j],
                                     prev[1][j]);
                    } else {
                        profit = max(p[i] + prev[1][j+1],
                                    prev[0][j]);
                    }
                    curr[buy][j] = profit;
                }
                
            }
            prev=curr;
        }
        return prev[1][0];
    }
};
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {

        int m = a.size();
        int n = a[0].size();
        if (a[0][0] == 1 || a[m - 1][n - 1] == 1)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1)
                    continue;
                if (i == 0 && j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;
                if (i > 0) {
                    up = dp[i - 1][j];
                }
                if (j > 0) {
                    left = dp[i][j - 1];
                }
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};

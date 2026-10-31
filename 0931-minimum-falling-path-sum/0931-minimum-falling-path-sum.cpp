class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {

        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: Last row
        for (int j = 0; j < m; j++) {
            dp[n-1][j] = arr[n-1][j];
        }

        // Bottom-up traversal
        for (int i = n-2; i >= 0; i--) {

            for (int j = 0; j < m; j++) {

                int dl = INT_MAX;
                int dd = INT_MAX;
                int dr = INT_MAX;

                if (j-1 >= 0)
                    dl = dp[i+1][j-1];

                dd = dp[i+1][j];

                if (j+1 < m)
                    dr = dp[i+1][j+1];

                dp[i][j] = arr[i][j] + min({dl, dd, dr});
            }
        }

        // Any starting column in first row
        int hm = INT_MAX;

        for (int j = 0; j < m; j++) {
            hm = min(hm, dp[0][j]);
        }

        return hm;
    }
};
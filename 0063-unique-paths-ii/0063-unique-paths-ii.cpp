class Solution {
public:
    int help(int i, int j, int m, int n, vector<vector<int>>& dp,
             vector<vector<int>>& a) {

        if (i == m - 1 && j == n - 1) {

            return 1;
        }

        if (i >= m || j >= n || i < 0 || j < 0 || a[i][j] == 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] =
                   help(i, j + 1, m, n, dp, a) + help(i + 1, j, m, n, dp, a);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        
        int m = a.size();
        int n = a[0].size();
        if(a[0][0] ==1|| a[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return help(0, 0, m, n, dp, a);
    }
};

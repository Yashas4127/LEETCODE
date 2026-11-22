class Solution {
public:
    int help(int i, int j, const string& t1, const string& t2,
             vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (t1[i] == t2[j]) {
            return dp[i][j] = 1 + help(i - 1, j - 1, t1, t2, dp);
        }
        int nMi = help(i - 1, j, t1, t2, dp);
        int nMj = help(i, j - 1, t1, t2, dp);
        return dp[i][j] = max(nMi, nMj);
    }

    int minInsertions(string s1) {
        string s2 = s1;
        int n = s1.size();
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= n; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                else {
                    int nMi = dp[i - 1][j];
                    int nMj = dp[i][j - 1];
                    dp[i][j] = max(nMi, nMj);
                }
            }
        }

        return n - dp[n][n];
    }
};
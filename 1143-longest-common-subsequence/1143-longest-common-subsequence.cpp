class Solution {
public:
    int help(int i, int j, string& t1, string& t2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (t1[i] == t2[j]) {
            return dp[i][j] = 1 + help(i - 1, j - 1, t1, t2, dp);
        }
        int nMi = help(i - 1, j, t1, t2, dp);
        int nMj = help(i, j - 1, t1, t2, dp);
        return dp[i][j] = max(nMi, nMj);
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        for (int i = 0; i <= n1; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= n2; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
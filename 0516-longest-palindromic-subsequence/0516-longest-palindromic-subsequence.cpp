class Solution {
public:
    int help(int i, int j, string &t1, string &t2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (t1[i] == t2[j]) {
            return dp[i][j]=1 + help(i - 1, j - 1, t1, t2, dp);
        }
        int nMi = help(i - 1, j, t1, t2, dp);
        int nMj = help(i, j - 1, t1, t2, dp);
        return dp[i][j] = max(nMi, nMj);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return help(n - 1, n - 1, s, rev, dp);
    }
};
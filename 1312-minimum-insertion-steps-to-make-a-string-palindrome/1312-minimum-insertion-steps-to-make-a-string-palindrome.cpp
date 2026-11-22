class Solution {
public:
    int help(int i, int j, const string& t1, const string& t2, vector<vector<int>>& dp) {
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
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int p = help(n - 1, n - 1, s1, s2, dp);
        return n - p;
    }
};
class Solution {
public:
    int dp[1001][1001];

    bool solve(const string& s, int l, int r) {
        if (l >= r)
            return true;
        if (dp[l][r] != -1)
            return dp[l][r] == 1;

        bool isPal = false;
        if (s[l] == s[r]) {
            isPal = solve(s, l + 1, r - 1);
        }
        dp[l][r] = isPal ? 1 : 0;
        return isPal;
    }

    int countSubstrings(string s) {
        int n = s.size();
        if (n == 0)
            return 0;

        memset(dp, -1, sizeof(dp));
        int hm=0;
        int startInd = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (solve(s, i, j)) {
                    hm++;
                }
            }
        }
        return hm;
    }
};
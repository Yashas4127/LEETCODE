class Solution {
public:
    int minDistance(string s1, string s2) {
        

        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        for (int i = 0; i <= n1; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= n2; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
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
        cout<<n1+n2<<" "<<dp[n1][n2];
        return n1-dp[n1][n2] + n2-dp[n1][n2];
    }
};
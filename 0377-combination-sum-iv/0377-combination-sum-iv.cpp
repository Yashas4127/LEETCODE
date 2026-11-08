
class Solution {
public:
    int perm(vector<int>& a, int t, int n, vector<int>& dp) {

        if (t < 0)
            return 0;

        if (t == 0)
            return 1;

        if (dp[t] != -1)
            return dp[t];

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += perm(a, t - a[i], n, dp);
        }

        return dp[t] = ans;
    }

    int combinationSum4(vector<int>& nums, int t) {

        int n = nums.size();

        vector<int> dp(t + 1, -1);
        dp[0] = 1;
        for (int ind = 1; ind <=t; ind++) {
            long long ans = 0;

            for (int i = 0; i < n; i++) {
                if (ind >= nums[i]) {
                    ans += dp[ind - nums[i]];
                }
            }
            dp[ind] = ans;
        }
        return dp[t];
    }
};

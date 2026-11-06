class Solution {
public:
    bool help(int i, int k, int n, vector<int>& a, vector<vector<int>>& dp) {
        if (dp[i][k] != -1)
            return dp[i][k];
        if (k == 0)
            return true;
        if (i == 0)
            return a[0] == k;
        bool notTake = help(i - 1, k, n, a, dp);
        bool take = false;
        if (k >= a[i]) {
            take = help(i - 1, k - a[i], n, a, dp);
        }
        return dp[i][k] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        int n = nums.size();
        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++) {
            // if target==0
            dp[i][0] = true;
        }
        // if i==0 and nums[o]==target
        if (nums[0] == target)
            dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <=target; j++) {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (j >= nums[i]) {
                    take = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = take | notTake;
            }
        }
        return dp[n-1][target];
    }
};
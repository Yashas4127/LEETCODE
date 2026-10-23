class Solution {
public:
    int help(vector<int>& dp, vector<int>& nums, int i, int n) {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int rob = nums[i] + help(dp, nums, i + 2, n);
        int skip = help(dp, nums, i + 1, n);
        return dp[i] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        int one=help(dp1,nums,0,n-1);
        int two=help(dp2,nums,1,n);

        return max(one,two);
    }
};
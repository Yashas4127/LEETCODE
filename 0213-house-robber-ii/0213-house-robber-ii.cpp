class Solution {
public:
    int help(vector<int>& dp, vector<int>& nums, int i, int n) {
      for(int i=n-1;i>=0;i--){
        int rob=nums[i]+dp[i+2];
        int skip=dp[i+1];
        dp[i]=max(rob,skip);
      }
      return dp[i];

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp1(n+2,0);
        vector<int>dp2(n+2,0);
        int one=help(dp1,nums,0,n-1);
        int two=help(dp2,nums,1,n);

        return max(one,two);
    }
};
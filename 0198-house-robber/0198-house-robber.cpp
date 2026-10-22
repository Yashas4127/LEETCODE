class Solution {
public:
    int help(vector<int>& dp,vector<int>&nums,int i,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int rob=nums[i]+help(dp,nums,i+2,n);
        int skip=help(dp,nums,i+1,n);
        return dp[i]=max(rob,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return help(dp,nums,0,nums.size());
    }
};
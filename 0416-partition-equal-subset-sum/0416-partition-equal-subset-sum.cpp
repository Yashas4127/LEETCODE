class Solution {
public:
bool help(int i,int k,int n,vector<int>&a,vector<vector<int>>&dp){
    if(dp[i][k]!=-1)return dp[i][k];
    if(k==0) return true;
    if(i==0) return a[0]==k;
    bool notTake=help(i-1,k,n,a,dp);
    bool take=false;
    if(k>=a[i]){
        take=help(i-1,k-a[i],n,a,dp);
    }
    return dp[i][k]=take|| notTake;

}
    bool canPartition(vector<int>& nums) {
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum,-1));
        return help(n-1,sum/2,n,nums,dp);
    }
};
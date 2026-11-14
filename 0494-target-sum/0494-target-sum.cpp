class Solution {
public:
int help(int i,int target,vector<int>&nums){
    
    if(i==0){
        if(target==0 && nums[0]==0) return 2;
        if(target+nums[0]==0) return 1;
        if(target-nums[0]==0) return 1;
        
         return 0;
          
    }
    
    int pos=help(i-1,target+nums[i],nums);
    int neg=help(i-1,target-nums[i],nums);

    return pos+neg;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return help(n-1,target,nums);
    }
};
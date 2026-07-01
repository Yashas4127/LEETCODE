class Solution {
public:
    int countsubarray(vector<int>&nums,int k){
        if(k<0){
            return 0;
        }
        long long sum=0;
        long long c=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            c+=(i-l+1);
        }
        return int(c);
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countsubarray(nums,goal)-countsubarray(nums,goal-1);
    }
};
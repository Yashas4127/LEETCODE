class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        int hm=n;
        while(low<=high){
            int mid=(low+high)>>1;

            if(nums[mid]>=target){
                hm=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return hm;
    }
};
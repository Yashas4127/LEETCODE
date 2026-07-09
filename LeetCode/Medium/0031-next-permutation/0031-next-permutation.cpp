class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find pivot find from last
        int indx=-1;

        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                indx=i;
                break;
            }
        }
        //if pivot does not exit
        if(indx==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        //swap pivot with minmum element which is greater from pivot
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[indx]){
                swap(nums[i],nums[indx]);
                break;
            }
        }
        //reverse right part of the pivot
        reverse(nums.begin()+indx+1,nums.end());
    }
};
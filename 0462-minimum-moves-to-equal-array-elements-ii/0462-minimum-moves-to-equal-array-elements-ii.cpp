class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median=nums[nums.size()/2];

        int hm=0;
        for(int it:nums){
            hm+=abs(median-it);
        }
        return hm;
    }
};
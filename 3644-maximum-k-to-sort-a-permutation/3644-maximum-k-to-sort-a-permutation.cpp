class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int hm=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                hm=hm&nums[i];
            }

        }
        return max(hm,0);
    }

};
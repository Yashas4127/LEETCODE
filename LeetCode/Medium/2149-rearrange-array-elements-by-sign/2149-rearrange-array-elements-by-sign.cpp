class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pI=0,nI=1;
        vector<int>hm(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                hm[pI]=nums[i];
                pI+=2;
            }
            else{
                hm[nI]=nums[i];
                nI+=2;
            }
        }
        return hm;
    }
};
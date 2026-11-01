class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int miniEle=*min_element(nums.begin(),nums.end());
        int hm=0;

        for(int it:nums){
            hm+=it-miniEle;
        }
        return hm;

        
    }
};
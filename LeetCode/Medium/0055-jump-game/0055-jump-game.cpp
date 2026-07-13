class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxR=0;
        for(int i=0;i<nums.size();i++){

            //2 3 1 1 4
            //0 1 2 3 4
            //maxR=2 4 3 4 8 true


            //3 2 1 0 4
            //0 1 2 3 4
            //maxR=3 3 3 3 8  but here 4(next index)>3 false

            //if index greater than maxR it means 
            //maxR=3 ,index=5 than it can never reach there
            if(i>maxR) return false;
            maxR=max(maxR,i+nums[i]);
        }
        return true;
    }
};
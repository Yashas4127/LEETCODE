class Solution {
public:
    int jump(vector<int>& nums) {
        int left=0,right=0;
        
        int hm=0;
        while(right<nums.size()-1){
            int farthest=0;//maximum distance it can reach 
            for(int i=left;i<=right;i++){
                farthest=max(farthest,i+nums[i]);
            }
            hm++;

            left=right+1;
            right=farthest;
        }

        return hm;


    }
};
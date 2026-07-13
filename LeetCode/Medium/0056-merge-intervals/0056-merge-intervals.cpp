class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>>hm;

        hm.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i][0]>hm.back()[1]){
                hm.push_back(nums[i]);
            }
            else{
                hm.back()[1]=max(hm.back()[1],nums[i][1]);
            }
        }
        return hm;
    }
};
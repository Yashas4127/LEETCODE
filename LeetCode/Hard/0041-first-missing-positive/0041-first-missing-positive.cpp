class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());

        unordered_map<int,int>mpp;

        for(int it: nums){
            mpp[it]++;
        }

        int i=0;
        for(i=1;i<=maxi;i++){
            if(mpp.find(i)==mpp.end()){
               break;
            }
        }
        return i;
    }
};
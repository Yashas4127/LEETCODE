class Solution {
public:
    int help(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int hm=0;
        int left=0,right=0;

        while(right<nums.size()){
            m[nums[right]]++;

            while(m.size()>k){
                m[nums[left]]--;
                if(m[nums[left]]==0){
                    m.erase(nums[left]);
                }
                left++;
            }
            right++;
            hm+=right-left+1;
        }
        return hm;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums, k) - help(nums, k - 1);
    }
};
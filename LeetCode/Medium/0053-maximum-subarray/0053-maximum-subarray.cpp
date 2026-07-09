class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int hm = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            hm = max(sum, hm);
            if (sum < 0) {

                sum = 0;
            }
        }
        return hm;
    }
};
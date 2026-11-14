class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();
        int hm = INT_MAX;

        for (int left = 0; left < n; left++) {
            int sum = 0;
            for (int end = left; end < n && end < left + r; end++) 
            {
                 sum += nums[end];
                int len = end - left + 1;
                if (len >= l && len <= r && sum > 0) {
                    hm = min(hm, sum);
                }
            }
        }

        return hm == INT_MAX ? -1 : hm;
    }
};
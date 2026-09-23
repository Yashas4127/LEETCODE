class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ele = sum - x;
        if (ele < 0) return -1;
        if (ele == 0) return nums.size();
        int low = 0, high = 0;
        int sumA = 0;
        int hm = -1;
        while (high<nums.size()) {
            sumA += nums[high];
            while (sumA > ele) {
                sumA -= nums[low];
                low++;
            }
            if (sumA == ele) {

                hm = max(hm, high - low + 1);
            }
            high++;
        }

        return hm == -1 ? -1 : nums.size() - hm;
    }
};
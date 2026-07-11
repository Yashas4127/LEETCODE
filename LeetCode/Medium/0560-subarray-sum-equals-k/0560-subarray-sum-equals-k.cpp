class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        int prefix=0;
        m[0] = 1;
        int hm = 0;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];

            int preSum = prefix - k;
            hm += m[preSum];
            m[prefix]++;
        }
        return hm;
    }
};
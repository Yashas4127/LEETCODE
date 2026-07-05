class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int hm = 0;
        int dR = 0;
        int maxi = 0, mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            maxi = 0, mini = INT_MAX;
            int size = s.size();
            for (int j = 0; j < s.size(); j++) {
                maxi = max(maxi, s[j] - '0');
                mini = min(mini, s[j] - '0');
            }
            dR = max(dR, maxi - mini);
        }
        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            maxi = 0, mini = INT_MAX;
            int size = s.size();
            for (int j = 0; j < s.size(); j++) {
                maxi = max(maxi, s[j] - '0');
                mini = min(mini, s[j] - '0');
            }
            if (dR == maxi - mini) {
                hm += nums[i];
            }
        }
        return hm;
    }
};
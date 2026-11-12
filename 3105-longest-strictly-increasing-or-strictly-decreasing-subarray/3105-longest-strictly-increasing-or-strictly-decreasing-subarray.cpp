
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi = 1;
        int mini = 1;

        int count1 = 1;
        int count2 = 1;

        for (int i = 0; i < nums.size() - 1; i++) {

            if (nums[i] > nums[i + 1]) {
                count1++;
                count2 = 1;
            }
            else if (nums[i] < nums[i + 1]) {
                count2++;
                count1 = 1;
            }
            else {
                count1 = 1;
                count2 = 1;
            }

            maxi = max(maxi, count1);
            mini = max(mini, count2);
        }

        return max(maxi, mini);
    }
};

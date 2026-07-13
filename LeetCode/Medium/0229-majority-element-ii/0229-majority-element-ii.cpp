class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int ele1 = 0, ele2 = 0;

        for (int num : nums) {
            if (num == ele1) {
                count1++;
            }
            else if (num == ele2) {
                count2++;
            }
            else if (count1 == 0) {
                ele1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                ele2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;

        for (int num : nums) {
            if (num == ele1) count1++;
            else if (num == ele2) count2++;
        }

        vector<int> ans;
        int limit = nums.size() / 3;

        if (count1 > limit) ans.push_back(ele1);
        if (count2 > limit) ans.push_back(ele2);

        return ans;
    }
};
class Solution {
public:
int help(vector<int>& nums, int k) {
        int eN = 0;
        int oN = 0;
        int left = 0, right = 0;
        int hm = 0;
        int n = nums.size();
        if(k<0) return 0;
        while (right < nums.size()) {
            if (nums[right] % 2 == 1) {
                oN++;
            } else {
                eN++;
            }

            while (oN > k) {
                if (nums[left] % 2 == 1) {
                    oN--;
                } else {
                    eN--;
                }
                left++;
            }
            if(oN<=k) hm+=(right-left+1);
            right++;
        }
        return hm;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
    }
};
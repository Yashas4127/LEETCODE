class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);



        int n = nums.size();
        int target = sum/2;

        vector<bool> prev(target + 1, false);

        prev[0] = true;

        if (nums[0] <= target)
            prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {

            vector<bool> curr(target + 1, false);
            curr[0] = true;

            for (int j = 1; j <= target; j++) {

                bool notTake = prev[j];

                bool take = false;

                if (j >= nums[i]) {
                    take = prev[j - nums[i]];
                }

                curr[j] = take || notTake;
            }

            prev = curr;
        }

        int hm=INT_MAX;
        for(int i=0;i<=target;i++){
            if(prev[i])
            hm=min(sum-i-i,hm);
        }
        return hm;
    }
};
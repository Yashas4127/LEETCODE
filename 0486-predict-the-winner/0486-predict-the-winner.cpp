class Solution {
public:
    bool solve(vector<int>& nums, int p1, int p2, int i, int j, bool turn) {
        if (i > j)
            return p1 >= p2;
        if (turn) {
            //To win any one path is enough
            return solve(nums, p1 + nums[i], p2, i + 1, j, false) ||
                   solve(nums, p1 + nums[j], p2, i, j - 1, false);
        } else {
            //To loose both should loose
            return solve(nums, p1, p2 + nums[i], i + 1, j, true) &&
                   solve(nums, p1, p2 + nums[j], i, j - 1, true);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int player1 = 0;
        int player2 = 0;
        return solve(nums, player1, player2, i, j, true);
    }
};
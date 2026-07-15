class Solution {
public:
    int lowerbound(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int upperbound(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] > k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans - 1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerbound(nums, target);
        if (lb == nums.size() || nums[lb] != target)
            return {-1, -1};
        int ub = upperbound(nums, target);
        return {lb, ub};
    }
};
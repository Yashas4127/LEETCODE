class Solution {
public:
    void heapify(vector<int>& nums, int i, int n) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[largest] < nums[left]) {
            largest = left;
        }
        if (right < n && nums[largest] < nums[right]) {
            largest = right;
        }

        if (largest != i) {
            swap(nums[largest], nums[i]);
            heapify(nums, largest, n);
        }
    }

    void heapSort(vector<int>& arr, int n) {
        if (n <= 1)
            return;
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, i, n);
        }

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, 0, i);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums, nums.size());
        return nums;
    }
};
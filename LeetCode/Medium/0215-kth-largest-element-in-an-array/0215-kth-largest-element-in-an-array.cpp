class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int> maxHeap(arr.begin(), arr.end());

        int hm = 0;
        while (k--) {
            hm = maxHeap.top();
            maxHeap.pop();
        }
        return hm;
    }
};
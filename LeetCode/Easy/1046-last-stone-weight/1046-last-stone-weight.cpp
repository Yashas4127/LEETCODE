class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());

        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();

            if (first == second) {
                continue;
            } else {
                maxHeap.push(first - second);
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        unordered_map<int, int> counts;

        for (auto n : arr) {
            counts[n]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &p : counts) {
            pq.push(p.second);
        }

        while (k > 0) {
            int freq = pq.top();

            if (k >= freq) {
                k -= freq;
                pq.pop();
            } else {
                break;
            }
        }

        return pq.size();
    }
};
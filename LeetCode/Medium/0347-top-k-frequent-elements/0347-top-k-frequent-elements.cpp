class Solution {
public:
    class cmp {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int it : nums) {
            mpp[it]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        for (auto it : mpp) {
            pq.push({it.first, it.second});
        }
        vector<int> hm;
        pair<int, int> ele;
        while (k--) {
            ele = pq.top();
            pq.pop();
            hm.push_back(ele.first);
        }
        return hm;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int minE = nums[0][0];
        int maxE = nums[0][0];

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], {i, 0}});
            minE = min(minE, nums[i][0]);
            maxE = max(maxE, nums[i][0]);
        }

        vector<int> hm;
        hm.push_back(minE);
        hm.push_back(maxE);
        pair<int, pair<int, int>> ele;
        int ci, ri;

        while (pq.size() == nums.size()) {
            ele = pq.top();
            pq.pop();
            ri = ele.second.first;
            ci = ele.second.second;
            ci++;
            if (ci < nums[ri].size()) {
                pq.push({nums[ri][ci], {ri, ci}});
                maxE = max(maxE, nums[ri][ci]);
                minE = pq.top().first;
            }

            if (maxE - minE < hm[1] - hm[0]) {
                hm[1] = maxE;
                hm[0] = minE;
            }
        }
        return hm;
    }
};
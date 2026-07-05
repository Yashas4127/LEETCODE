class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();

        vector<pair<int, pair<int, int>>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({mat[i][0], {i, 0}});
        }
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq(temp.begin(), temp.end());

        int hm;
        pair < int, pair < int, int >> ele;

        while (k--) {
            ele = pq.top();
            pq.pop();
            hm = ele.first;
            int rowInd = ele.second.first;
            int colInd = ele.second.second;
            if (colInd < mat.size() - 1)
                pq.push({mat[rowInd][colInd + 1], {rowInd, colInd + 1}});
        }
        return hm;
    }
};
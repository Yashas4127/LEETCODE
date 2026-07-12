class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> hm;
        unordered_map<int, int> m;
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        int r=1;
        for (int i = 0; i < n; i++) {
            if (m.find(temp[i]) == m.end())
                m[temp[i]] = r++;
        }

        for (int i = 0; i < n; i++) {
            int indx = m[arr[i]];
            hm.push_back(indx);
        }

        return hm;
    }
};
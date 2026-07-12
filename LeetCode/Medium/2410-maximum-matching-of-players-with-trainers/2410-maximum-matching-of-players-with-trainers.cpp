class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        if (g.size() == 0)
            return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int count = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return count;
    }

};
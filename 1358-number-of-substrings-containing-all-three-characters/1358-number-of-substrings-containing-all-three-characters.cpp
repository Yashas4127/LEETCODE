class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> hash(3, -1);
        int hm = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            hash[s[i] - 'a'] = i;

            if (hash[0] >= 0 && hash[1] >= 0 && hash[2] >= 0) {
                hm += 1 + min({hash[0], hash[1], hash[2]});
            }
        }

        return hm;
    }
};
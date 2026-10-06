class Solution {
public:
    int minAddToMakeValid(string s) {
        int hm = 0;
        int n = s.size();
        int depth = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                depth++;
            else
                depth--;
            if (depth < 0) {
                hm++;
                depth = 0;
            }
        }
        hm += depth;
        return hm;
    }
};
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int hm = 0;

        for(auto str : words) {
            int i = 0;

            for(int j = 0; j < str.size(); j++) {

                if(i >= s.size() || str[j] != s[i]) {
                    break;
                }

                i++;
            }

            if(i == str.size()) {
                hm++;
            }
        }

        return hm;
    }
};
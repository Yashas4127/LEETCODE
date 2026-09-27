class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();

        unordered_map<string, string> mp;

        // Store key -> value
        for (auto& k : knowledge) {
            mp[k[0]] = k[1];
        }
        string hm = "";
        for (int i = 0; i < n; i++) {
            string ts = "";
            if (s[i] == '(') {
                i++;
                while (s[i] != ')') {
                   
                    ts.push_back(s[i]);
                    i++;
                }
                if (mp.find(ts)!=mp.end()) {
                    hm+=mp[ts];
                } else {
                    hm+='?';
                }
                continue;
            }
            hm+=s[i];
        }
        return hm;
    }
};
class Solution {
private:
    unordered_set<string> st;

public:
    void help(string &s, int i, int n, int oc, int cc, string &ans, int &maxN) {
        if (cc > oc)
            return;
        if (i == n) {
            if (oc == cc) {
                if (ans.size() > maxN) {
                    st.clear();
                    st.insert(ans);
                    maxN = ans.size();
                } else if (ans.size() == maxN) {
                    st.insert(ans);
                }
            }
            return;
        }

        if (s[i] != '(' && s[i] != ')') {
            ans.push_back(s[i]);
            help(s, i + 1, n, oc, cc, ans, maxN);
            ans.pop_back();
            return;
        } else {
            if (s[i] == ')') {
                ans.push_back(s[i]);
                help(s, i + 1, n, oc, cc + 1, ans, maxN);
                ans.pop_back();
            } else {
                ans.push_back(s[i]);
                help(s, i + 1, n, oc + 1, cc, ans, maxN);
                ans.pop_back();
            }
            help(s, i + 1, n, oc, cc, ans, maxN);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> hm;

        int n = s.size();

        string ans = "";
        int maxN = 0;
        help(s, 0, n, 0, 0, ans, maxN);
        for (string ss : st) {
            hm.push_back(ss);
        }
        return hm;
    }
};
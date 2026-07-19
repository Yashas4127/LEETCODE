class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> seen(26, false);
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (seen[s[i] - 'a'])
                continue;

            while (!st.empty() && st.top() > s[i] &&
                   lastIndex[st.top() - 'a'] > i) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i] - 'a'] = true;
        }
        string hm;
        while (!st.empty()) {
            hm.push_back(st.top());
            st.pop();
        }
        reverse(hm.begin(), hm.end());

        return hm;
    }
};
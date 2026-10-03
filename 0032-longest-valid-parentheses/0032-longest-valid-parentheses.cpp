class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int n = s.size();
        int hm = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                st.pop();
                if (st.empty()) {
                    st.push(i);

                } else {
                    hm = max(hm, i - st.top());
                }

            } else {
                st.push(i);
            }
        }
        return hm;
    }
};
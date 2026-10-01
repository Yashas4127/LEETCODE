class Solution {
public:
    bool isValid(string& s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (st.empty() || s[i] == '(' || s[i] == '{' || s[i] == '[') {
                if (s[i] == '(')
                    st.push(')');
                else if (s[i] == '{')
                    st.push('}');
                else if (s[i] == '[')
                    st.push(']');
                else
                    return 0;
            } else {
                if (st.top() == s[i])
                    st.pop();
                else
                    return 0;
            }
        }
        return st.empty();
    }
};
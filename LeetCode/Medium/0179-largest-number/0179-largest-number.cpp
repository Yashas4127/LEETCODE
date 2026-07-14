bool cmp(string a, string b) {
    return a + b > b + a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;

        s.reserve(nums.size());

        for (int x : nums) {
            s.push_back(to_string(x));
        }

        sort(s.begin(), s.end(), cmp);

        // If the largest element is 0, all elements are 0
        if (!s.empty() && s[0] == "0")
            return "0";

        string ans;

        int length = 0;
        for (const string &st : s)
            length += st.length();

        ans.reserve(length);

        for (const string &st : s)
            ans += st;

        return ans;
    }
};
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n, 0);
        int hm = 0;
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                ans[i]=hm%2;
                hm++;

            } else {
                hm--;
                ans[i]=hm%2;
            }
        }
        return ans;
    }
};
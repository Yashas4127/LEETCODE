class Solution {
public:
    void computeLPS(string& pattern, vector<int>& lps) {
        int m = pattern.size();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    bool isPossible(string& pat, string& txt) {
        int n = txt.size();
        int m = pat.size();

        vector<int> lps(m, 0);
        computeLPS(pat, lps);

        int i = 0;
        int j = 0;

        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) {
                return true;
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int hm = 0;
        int n = nums.size();
        if (nums == sorted) {
            for (int i = 1; i <= n; i++) {
                if (n % i == 0)
                    hm += i;
            }
            return hm;
        }
        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;
            bool valid =true;
            

            for (int start = 0; start < n; start += k) {
                string str;
                string p;

                for (int i = start; i < start + k && i < n; i++) {
                    str.push_back(nums[i] + '0');
                    p.push_back(sorted[i] + '0');
                }

                str += str;

               if (!isPossible(p, str)) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                hm += k;
        }

        return hm;
    }
};
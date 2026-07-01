vector<int> lps(100);

class Solution {
public:
    static void buildLPS(const string& s) {

        int len = 0;
        int i = 1;

        while (i < s.size()) {

            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            }

            else {

                if (len != 0) {
                    len = lps[len - 1];
                }

                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    static int KMP(const string& text, const string& pattern) {

        buildLPS(pattern);

        int i = 0;
        int j = 0;

        while (i < text.size()) {

            while (j > 0 && text[i] != pattern[j]) {
                j = lps[j - 1];
            }

            if (text[i] == pattern[j]) {
                j++;
            }

            if (j == pattern.size()) {
                return i - j + 1;
            }

            i++;
        }

        return -1;
    }

    int numOfStrings(vector<string>& patterns, string word) {

        int hm = 0;

        for (string p : patterns) {

            if (KMP(word, p) != -1)
                hm++;
        }

        return hm;
    }
};
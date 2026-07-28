class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> hash(256, 0);
        for (char ch : s) {
            hash[ch]++;
        }
        int n = s.size();
        string hm(n, ' ');

        int low = 0, high = n - 1;
        int mid = (low + high) >> 1;

        for (int i = 0; i < 256; i++) {
            while (hash[i] > 1) {
                hm[low] = (char)i;
                hm[high] = (char)i;
                low++, high--;
                hash[i] -= 2;
            }
            if (hash[i] == 1) {
                hm[mid] = (char)i;
            }
        }
        return hm;
    }
};
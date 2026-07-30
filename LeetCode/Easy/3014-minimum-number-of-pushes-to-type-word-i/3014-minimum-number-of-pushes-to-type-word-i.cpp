class Solution {
public:
    int minimumPushes(string word) {
        int count = 2;
        int n = word.size();

        if (n <= 8)
            return n;

        int hm = 8;
        n -= 8;

        while (n > 0) {
            if (n > 8) {
                hm += 8 * count;
                count++;
                n -= 8;
            } else {
                hm += n * count;
                n = 0;
            }
        }

        return hm;
    }
};
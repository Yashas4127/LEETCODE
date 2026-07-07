class Solution {
public:
    long long sumAndMultiply(int n) {
        long long hm = 0;
        long long sum = 0;
        long long s = 0;
        long long p = 1;

        while (n) {
            int rem = n % 10;
            sum += rem;
            if (rem != 0) {

                s += rem * p;
                p *= 10;
            }
            n /= 10;
        }

        hm = s * sum;

        return hm;
    }
};
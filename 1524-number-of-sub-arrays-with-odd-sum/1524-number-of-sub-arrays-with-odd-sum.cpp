class Solution {
public:
    int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {

        int n = arr.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        long long oc = 0;
        long long ec = 0;
        long long hm = 0;

        for (int i = 0; i <= n; i++) {

            if (prefix[i] % 2 == 0) {
                hm = (hm + oc) % MOD;
                ec++;
            }
            else {
                hm = (hm + ec) % MOD;
                oc++;
            }
        }

        return hm;
    }
};
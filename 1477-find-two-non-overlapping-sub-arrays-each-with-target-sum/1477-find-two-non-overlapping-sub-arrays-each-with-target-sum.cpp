class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        int INF = 1e9;

        vector<int> prefix(n + 1, INF);
        vector<int> suffix(n + 1, INF);

        int sum = 0;
        int start = 0;
        int minLen = INF;

        for (int i = 0; i < n; i++) {

            sum += arr[i];

            while (sum > target) {
                sum -= arr[start++];
            }

            if (sum == target) {
                int len = i - start + 1;
                minLen = min(minLen, len);
            }

            prefix[i + 1] = minLen;
        }
        sum = 0;
        int end = n - 1;
        minLen = INF;

        for (int i = n - 1; i >= 0; i--) {

            sum += arr[i];

            while (sum > target) {
                sum -= arr[end--];
            }

            if (sum == target) {
                int len = end - i + 1;
                minLen = min(minLen, len);
            }

            suffix[i] = minLen;
        }

        int ans = INF;

        for (int i = 0; i <= n; i++) {

            if (prefix[i] != INF && suffix[i] != INF) {
                ans = min(ans, prefix[i] + suffix[i]);
            }
        }

        return ans == INF ? -1 : ans;
    }
};
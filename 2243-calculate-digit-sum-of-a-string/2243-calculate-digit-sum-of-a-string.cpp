class Solution {
public:
    string digitSum(string s, int k) {
        string sC = s;

        while(sC.size() > k) {
            string ss = "";

            for(int i = 0; i < sC.size(); i += k) {
                int sum = 0;

                for(int j = i; j < min(i + k, (int)sC.size()); j++) {
                    sum += sC[j] - '0';
                }

                ss += to_string(sum);
            }

            sC = ss;
        }

        return sC;
    }
};
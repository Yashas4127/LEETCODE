class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>hashS(256,0);
        vector<int>hashT(256,0);

        for(int i =0;i<s.size();i++){
            hashS[s[i]]++;
            hashT[t[i]]++;
        }

        int hm=0;
        int sum=0;

        for(int i=0;i<256;i++){
            sum=abs(hashS[i]-hashT[i]);
            hm+=sum;
        }

        return hm/2;
    }
};
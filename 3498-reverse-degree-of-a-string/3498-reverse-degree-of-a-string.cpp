class Solution {
public:
    int reverseDegree(string s) {
        int hm=0;
        for(int i=0;i<s.size();i++){
            hm+=(i+1)*('z'-s[i]+1);
        }
        return hm;
    }
};
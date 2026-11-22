class Solution {
public:
    bool checkString(string s) {
       bool hm=false;
       int n=s.size();
       for(int i=n-1;i>=0;i--){
        if(s[i]=='a') hm=true;
        if(s[i]=='b' && hm) return false; 
       } 
       return true;
    }
};
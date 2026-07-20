class Solution {
public:
    bool checkValidString(string s) {
        int maxValue=0;
        int minValue=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                maxValue++;
                minValue++;
            }
            else if(s[i]==')'){
                maxValue--;
                minValue--;
            }
            else{
                maxValue++;
                minValue--;
            }
            if(maxValue<0) return false;
            if(minValue<0) minValue=0;
        }
        return minValue==0;
    }
};
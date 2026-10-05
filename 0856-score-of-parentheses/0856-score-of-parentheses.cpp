class Solution {
public:
    int scoreOfParentheses(string s) {
        int hm=0;
        int n=s.size();
        int depth=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
            }
            else{
                depth--;
                if(s[i-1]=='('){
                    hm+=1<<depth;
                }
            }
        }
        return hm;
    }
};
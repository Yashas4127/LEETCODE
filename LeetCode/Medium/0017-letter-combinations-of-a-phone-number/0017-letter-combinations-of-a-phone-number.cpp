class Solution {
public:
    void solve(string digits,string &output,int ind,vector<string> &ans,string mapping[]){
        if(ind>=digits.length()){
            ans.push_back(output);
            return ;
        }

        char num=digits[ind];
        int n=num-'0';
        for(int i=0;i<mapping[n].size();i++){
            output.push_back(mapping[n][i]);
            solve(digits,output,ind+1,ans,mapping);
             output.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
         vector<string> ans;
        if (digits.length() == 0) {
            return ans;
        }
        int i = 0;
        string output;
        string mapping[10] = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, i, ans, mapping);
        return ans;
    }
};
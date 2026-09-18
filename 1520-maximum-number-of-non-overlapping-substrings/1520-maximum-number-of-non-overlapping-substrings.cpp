class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int>start(26,-1);
        vector<int>end(26,0);
        vector<bool>isValid(26,true);

        vector<string>hm;
        for(int i=0;i<s.size();i++){
            if(start[s[i]-'a']==-1){
                start[s[i]-'a']=i;
            }
            end[s[i]-'a']=i;
        }

        for(int c=0;c<26;c++){
            if(start[c]==-1) continue;
            for(int i=start[c];i<=end[c];i++){
                if(start[s[i]-'a']<start[c]){
                    isValid[c]=false;
                    break;
                }
                end[c]=max(end[c],end[s[i]-'a']);
            }
        }
        int lastStart=1e9;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            int c=s[i]-'a';

            if(!isValid[c]) continue;
            if(i==start[c]&& end[c]<lastStart){
                hm.push_back(s.substr(i,end[c]-start[c]+1));
                lastStart=i;
            }
        }
        return hm;
    }
};
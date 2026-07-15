class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        int n=in.size();
        vector<vector<int>>hm;
        int i=0;
        while(i<n && ni[0]>in[i][1]){
            hm.push_back(in[i]);
            i++;
        }

        while(i<n && ni[1]>=in[i][0]){
            ni[0]=min(ni[0],in[i][0]);
            ni[1]=max(ni[1],in[i][1]);
            i++;
        }
        hm.push_back(ni);

        while(i<n){
           hm.push_back(in[i]);
            i++;
        }
        return hm;
    }
};
bool cmp(pair<int,int>&a ,pair<int,int>&b){
    return a.second<b.second;
}
class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int,int>>pq;
        for(int i=0;i<pairs.size();i++){
            pq.push_back({pairs[i][0],pairs[i][1]});
        }

        sort(pq.begin(),pq.end(),cmp);

        int end=INT_MIN;

        int hm=0;

        for(int i=0;i<pairs.size();i++){
            if(pq[i].first>end){
                end=pq[i].second;
                hm++;
            }
        }
        return hm;
    }
};

class Solution {
public:
  
vector<vector<int>> generate(int n){
    vector<vector<int>> ans2;
    for(int i=1;i<=n;i++){
        ans2.push_back(genrateRow(i));
    }
    return ans2;
}

private:

    vector<int> genrateRow(int n){
        vector<int>hm;
        int ans=1;
        hm.push_back(ans);
        for(int i=1;i<n;i++){
            ans=ans*(n-i)/i;
            hm.push_back(ans);
        }

        return hm;
    }

};
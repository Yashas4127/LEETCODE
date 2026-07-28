class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>s;

        for(int it:nums) s.insert(it);

        int hm=1;

        while(s.find(hm)!=s.end()){
            hm++;
        }
        return hm;
    }
};
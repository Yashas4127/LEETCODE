class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>hash(101,0);

        for(auto it: nums){
            hash[it]++;
        }

        int maxi=*max_element(hash.begin(),hash.end());
        int hm=0;
        for(auto it : hash){
            if(it==maxi){
                hm++;
            }
        }
        return hm*maxi;
    }
};
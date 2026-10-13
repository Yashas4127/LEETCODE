class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long hm=0;
        int n=nums.size();
        vector<int>a;
        for(int it: nums) a.push_back(abs(it));
        sort(a.begin(),a.end());
        int i=0,j=n-1;
        while(i<=j){
            if(i==j) hm+=(a[j]*a[j]);
            hm+=(a[j]*a[j])-(a[i]*a[i]);
            i++,j--;
        }

        return hm;
    }
};
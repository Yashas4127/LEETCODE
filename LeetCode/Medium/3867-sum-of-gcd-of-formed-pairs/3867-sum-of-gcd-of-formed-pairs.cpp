class Solution {
public:
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
    long long gcdSum(vector<int>& nums) {
        vector<int>prefixGcd;
        int n=nums.size();

        int maxi=INT_MIN;
        long long hm=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefixGcd.push_back(gcd(nums[i],maxi));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int l=0,h=n-1;
        while(l<h){
            hm+=gcd(prefixGcd[l],prefixGcd[h]);
            l++,h--;
        }
        return hm;
    }
};
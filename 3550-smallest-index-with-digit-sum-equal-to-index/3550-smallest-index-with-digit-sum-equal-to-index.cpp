class Solution {
public:
int sum(int i){
    int hm=0;
    while(i){
        hm+=i%10;
        i=i/10;
    }
    
    return hm;
}
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i==sum(nums[i])) return i;
        }
        return -1;
    }

};
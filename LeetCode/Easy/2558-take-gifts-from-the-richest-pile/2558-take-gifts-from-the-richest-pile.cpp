class Solution {
public:
    long long pickGifts(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());

        while(k>0){
            long long first=pq.top();
            pq.pop();

            first = floor(sqrt(first));
            pq.push(first);
            k--;
        }
        long long hm=0;
        while(pq.size()!=0){
            hm+=pq.top();
            pq.pop();
        }
        return hm;
    }
};
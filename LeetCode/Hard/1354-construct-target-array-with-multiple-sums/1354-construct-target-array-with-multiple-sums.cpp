class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long>pq;
        long long sum=0;

        for(auto it:target){
            sum+=it;
            pq.push(it);
        }

        long long maxEle,RemSum,Ele;
        while(pq.top()!=1){
            maxEle=pq.top();
            pq.pop();

            RemSum=sum-maxEle;
            if(RemSum<=0 || RemSum>=maxEle){
                return false;
            }
            Ele=maxEle%RemSum;
            if(Ele==0){
                if(RemSum!=1) return 0;
                else return 1;
            }
            sum=RemSum+Ele;
            pq.push(Ele);
        }
        return true;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>hash(26,0);
        int hm=0;

        for(char ch : tasks){
            hash[ch-'A']++;
        }

        int maxCount=0;

        for(int it : hash){
            maxCount=max(maxCount,it);
        }
        int maxEleCount=0;
        for(int it: hash){
            if(it==maxCount){
                maxEleCount++;
            }
        }
        //Important formula 
        hm=(maxCount-1)*(n+1)+maxEleCount;

        hm=max(hm,(int)tasks.size());

        return hm;

    }
};
class Solution {
public:
    class cmp {
    public:
        bool operator()(pair<char,int> a, pair<char,int> b) {
            return a.second < b.second;   
        }
    };

    string frequencySort(string s) {

        vector<int> hash(256,0);

        for(char ch : s){
            hash[ch]++;
        }

        priority_queue<pair<char,int>, vector<pair<char,int>>, cmp> minHeap;

        for(int i=0;i<256;i++){
            if(hash[i]!=0){
                minHeap.push({char(i), hash[i]});
            }
        }

        string ans="";

        while(!minHeap.empty()){

            pair<char,int> ele=minHeap.top();
            minHeap.pop();

            char ch=ele.first;
            int freq=ele.second;

            while(freq--){
                ans.push_back(ch);
            }
        }

        return ans;
    }
};
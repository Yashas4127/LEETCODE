class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hm=0;
        int mini=prices[0];
        for(int i=0;i<prices.size();i++){
            int profit=prices[i]-mini;
            hm=max(hm,profit);
            mini=min(mini,prices[i]);
        }
        return hm;
    }
};
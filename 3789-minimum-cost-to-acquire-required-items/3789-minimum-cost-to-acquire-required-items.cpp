class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long hm = 0;
     

        int cost = min(costBoth, cost1 + cost2);
        int need = min(need1, need2);
        hm +=  1LL *need * cost;
        need1 -= need;
        need2 -= need;
        hm += 1LL * need1 * min(cost1, costBoth);
        hm += 1LL * need2 * min(cost2, costBoth);

        return hm;
    }
};
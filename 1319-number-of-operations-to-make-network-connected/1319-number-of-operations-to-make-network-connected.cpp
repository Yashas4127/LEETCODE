class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    void unionByRank(int u, int v) {

        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraE = 0;
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            if (ds.findUpar(u) == ds.findUpar(v))
                extraE++;
            else{
                ds.unionByRank(u,v);
            }
        }
        int ans = 0;
        int nc = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUpar(i) == i)
                nc++;
        }
        ans = nc - 1;
        if (extraE >= ans)
            return ans;
        return -1;
    }
};
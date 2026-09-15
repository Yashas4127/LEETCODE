class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto edge : flights) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;
        // {stops,{node,dist}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            if (steps > k+1)
                continue;
            for (auto& p : adj[node]) {
                int n = p.first;
                int wt = p.second;

                if (dis + wt < dist[n] && steps <= k) {
                    dist[n] = dis + wt;
                    q.push({steps + 1, {n, dis + wt}});
                }
            }
        }
        return dist[dst]!=1e9?dist[dst]:-1;
    }
};
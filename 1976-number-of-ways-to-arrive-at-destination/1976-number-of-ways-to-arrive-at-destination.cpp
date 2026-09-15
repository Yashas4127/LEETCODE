#define P pair<long long, long long>
#define M int(1e9 + 7)

class Solution {
public:
   int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<P>> adj(n);
        for (auto it : roads) {
            long long u = it[0];
            long long v = it[1];
            long long wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<long long> dist(n, 1e18), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, 0});

        while (!q.empty()) {
            long long dis = q.top().first;
            long long node = q.top().second;
            q.pop();

            for (auto it : adj[node]) {
                long long aN = it.first;
                long long wt = it.second;

                if (dis + wt < dist[aN]) {
                    dist[aN] = dis + wt;
                    ways[aN] = ways[node];
                    q.push({dis + wt, aN});
                } else if (dis + wt == dist[aN]) {
                    ways[aN] = (ways[aN] + ways[node]) % M;
                }
            }
        }
        return ways[n - 1] % M;
    }
};
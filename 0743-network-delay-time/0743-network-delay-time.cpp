#define P pair<int,int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto edge : times) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        vector<int>dist(n+1,1e9);
        priority_queue<P,vector<P>,greater<P>>q;
        q.push({0,k});
        dist[k]=0;

        while(!q.empty()){
            P it=q.top();
            q.pop();

            int node=it.second;
            int dis=it.first;

            for(auto &p:adj[node]){
                int no=p.first;
                int wt=p.second;

                if(dist[no]>dis+wt){
                    dist[no]=dis+wt;
                    q.push({dis+wt,no});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
        } 
        return *max_element(dist.begin()+1,dist.end());
    }
};
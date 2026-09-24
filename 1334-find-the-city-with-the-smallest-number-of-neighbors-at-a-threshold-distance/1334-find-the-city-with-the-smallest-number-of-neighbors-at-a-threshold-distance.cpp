class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> w(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) {
            w[i][i] = 0;
        }

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            w[u][v] = wt;
            w[v][u] = wt;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
                }
            }
        }
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int cnt = 0;

            for (int j = 0; j < n; j++) {
                if (w[i][j] <= dt) {
                    cnt++;
                }
            }

            ans[i] = cnt;
        }

        int Mc = INT_MAX;
        int hm = -1;

        for (int i = 0; i < n; i++) {
            if (ans[i] <= Mc) {
                Mc = ans[i];
                hm = i;
            }
        }

        return hm;
    }
};
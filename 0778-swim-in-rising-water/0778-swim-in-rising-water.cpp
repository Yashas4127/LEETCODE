class Solution {
public:
    bool possible(int mid, int i, int j,
                  vector<vector<bool>>& vis,
                  vector<vector<int>>& grid, int n) {

        if (i >= n || i < 0 || j >= n || j < 0 ||
            vis[i][j] || grid[i][j] > mid) {
            return false;
        }

        vis[i][j] = true;

        if (i == n - 1 && j == n - 1) {
            return true;
        }

        int r[] = {1, 0, -1, 0};
        int c[] = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++) {
            int nr = i + r[k];
            int nc = j + c[k];

            if (possible(mid, nr, nc, vis, grid, n)) {
                return true;
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        int l = 0;
        int h = n * n - 1;

        while (l < h) {

            int mid = l + (h - l) / 2;

            vector<vector<bool>> vis(n, vector<bool>(n, false));

            if (possible(mid, 0, 0, vis, grid, n)) {
                h = mid;         
            }
            else {
                l = mid + 1;       
            }
        }

        return l;
    }
};
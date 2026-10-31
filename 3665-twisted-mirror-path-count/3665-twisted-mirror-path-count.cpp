
#define MOD 1000000007

class Solution {
public:
    int help(int i, int j, int n, int m,
             vector<vector<int>>& grid,
             vector<vector<int>>& dp) {

        if(i >= n || j >= m)
            return 0;

        if(i == n-1 && j == m-1)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = 0;
        int down = 0;

        // Move right
        int x = i;
        int y = j + 1;
        int dir = 0; // 0 = right, 1 = down

        while(x < n && y < m && grid[x][y] == 1) {
            if(dir == 0) {
                x++;
                dir = 1;
            }
            else {
                y++;
                dir = 0;
            }
        }

        right = help(x, y, n, m, grid, dp);

        // Move down
        x = i + 1;
        y = j;
        dir = 1;

        while(x < n && y < m && grid[x][y] == 1) {
            if(dir == 0) {
                x++;
                dir = 1;
            }
            else {
                y++;
                dir = 0;
            }
        }

        down = help(x, y, n, m, grid, dp);

        return dp[i][j] = (right + down) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return help(0, 0, n, m, grid, dp);
    }
};

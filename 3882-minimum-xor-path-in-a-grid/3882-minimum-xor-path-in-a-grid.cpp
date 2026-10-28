class Solution {
private:
    int helper(int r, int c, vector<vector<int>>& grid,
               int curXor, vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        if (r >= n || c >= m)
            return INT_MAX;

        curXor ^= grid[r][c];

        if (r == n - 1 && c == m - 1)
            return curXor;

        if (dp[r][c][curXor] != -1)
            return dp[r][c][curXor];

        int right = helper(r, c + 1, grid, curXor, dp);
        int down = helper(r + 1, c, grid, curXor, dp);

        return dp[r][c][curXor] = min(right, down);
    }

public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(1024, -1))
        );

        return helper(0, 0, grid, 0, dp);
    }
};
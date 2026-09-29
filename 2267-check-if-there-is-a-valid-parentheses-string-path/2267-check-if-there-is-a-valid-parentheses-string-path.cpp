class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool help(vector<vector<char>>& grid, int i, int j, int hm, int n, int m) {
        if (i >= n || i < 0 || j >= m || j < 0)
            return false;
        if (grid[i][j] == ')')
            hm--;
        else
            hm++;
        if (i == n - 1 && j == m - 1)
            return hm == 0;
        if (hm < 0)
            return false;
        if (dp[i][j][hm] != -1)
            return dp[i][j][hm];
        return dp[i][j][hm] = help(grid, i + 1, j, hm, n, m) ||
                              help(grid, i, j + 1, hm, n, m);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int hm = 0;
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] != '(' || grid[n - 1][m - 1] != ')')
            return false;
        dp.assign(n, vector<vector<int>>(m, vector<int>(n + m + 1, -1)));
        return help(grid, 0, 0, hm, n, m);
    }
};
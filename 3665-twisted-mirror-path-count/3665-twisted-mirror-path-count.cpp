#define MOD 1000000007

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        dp[n-1][m-1] = 1;

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {

                if(i == n-1 && j == m-1)
                    continue;

                int right = 0;
                int down = 0;

                // Move right
                int x = i;
                int y = j + 1;
                int dir = 0;

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

                if(x < n && y < m)
                    right = dp[x][y];

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

                if(x < n && y < m)
                    down = dp[x][y];

                dp[i][j] = (right + down) % MOD;
            }
        }

        return dp[0][0];
    }
};
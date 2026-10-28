func help(i, j int, grid, dp [][]int) int {
	if i < 0 || j < 0 {
		return math.MaxInt
	}
	if dp[i][j] != -1 {
		return dp[i][j]
	}

	if i == 0 && j == 0 {
		return grid[0][0]
	}

	up := math.MaxInt
	left := math.MaxInt

	if i > 0 {
		up = grid[i][j] + help(i-1, j, grid, dp)
	}
	if j > 0 {
		left = grid[i][j] + help(i, j-1, grid, dp)
	}

	dp[i][j] = min(up, left)
	return dp[i][j]
}

func minPathSum(grid [][]int) int {
	n := len(grid)
	m := len(grid[0])
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, m)
		for j := 0; j < m; j++ {
			dp[i][j] = -1
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if i == 0 && j == 0 {
				dp[i][j] = grid[i][j]
                continue;
			}
			up := math.MaxInt
			left := math.MaxInt

			if i > 0 {
				up = grid[i][j] +dp[i-1][j]
			}
			if j > 0 {
				left = grid[i][j] +dp[i][j-1]
			}

			dp[i][j] = min(up, left)
		}
	}
	return dp[n-1][m-1];
}
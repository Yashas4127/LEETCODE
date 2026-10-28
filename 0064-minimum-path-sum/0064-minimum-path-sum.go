// Space Optimization
func minPathSum(grid [][]int) int {
    n := len(grid)
    m := len(grid[0])

    prev := make([]int, m)

    for i := 0; i < n; i++ {
        curr := make([]int, m)

        for j := 0; j < m; j++ {
            if i == 0 && j == 0 {
                curr[j] = grid[i][j]
                continue
            }

            up := math.MaxInt
            left := math.MaxInt

            if i > 0 {
                up = grid[i][j] + prev[j]
            }

            if j > 0 {
                left = grid[i][j] + curr[j-1]
            }

            curr[j] = min(up, left)
        }

        prev = curr
    }

    return prev[m-1]
}
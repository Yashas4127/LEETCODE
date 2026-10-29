//Bottom up
func minimumTotal(triangle [][]int) int {
    n := len(triangle)

    dp := make([][]int, n)
    for i := 0; i < n; i++ {
        dp[i] = make([]int, len(triangle[i]))
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    for i:=0;i<n;i++{
        dp[n-1][i]=triangle[n-1][i];
    }
    for i:=n-2;i>=0;i--{
        for j:=i;j>=0;j--{
            d:=triangle[i][j]+dp[i+1][j]
            dg:=triangle[i][j]+dp[i+1][j+1]
            dp[i][j]=min(d,dg);
        }
    }
    return dp[0][0]
}
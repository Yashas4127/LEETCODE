//Space optimization
//front =dp[i+1]
//curr =dp[i]
func minimumTotal(triangle [][]int) int {
    n := len(triangle)

    front := make([]int, n)

    for i:=0;i<n;i++{
        front[i]=triangle[n-1][i];
    }
    for i:=n-2;i>=0;i--{
        curr := make([]int, n)
        for j:=i;j>=0;j--{
            d:=triangle[i][j]+front[j]
            dg:=triangle[i][j]+front[j+1]
            curr[j]=min(d,dg);
        }
        front=curr
    }
    return front[0]
}
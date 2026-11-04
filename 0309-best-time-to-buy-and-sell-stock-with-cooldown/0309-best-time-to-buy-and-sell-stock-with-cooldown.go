func help(i,n int ,p[]int ,buy int,dp[][]int) int{
    if i>=n{
        return 0;
    }
    if dp[i][buy]!=-1{
        return dp[i][buy]
    }
    profit:=0
    if buy==1{
        profit=max(-p[i]+help(i+1,n,p,0,dp),help(i+1,n,p,1,dp))
    }else{

        profit=max(p[i]+help(i+2,n,p,1,dp),help(i+1,n,p,0,dp));
    }

    dp[i][buy]=profit
    return profit;
}
func maxProfit(p []int) int {
    n:=len(p);
    dp:=make([][]int, n)
    for i:=range dp{
        dp[i]=[]int{-1,-1}
    }
    return help(0,n,p,1,dp)
}
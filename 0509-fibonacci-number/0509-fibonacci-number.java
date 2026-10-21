class Solution {
    int func(int n){
        if(n<=1 ) return n;
        return func(n-1)+func(n-2);
    }
    public int fib(int n) {
        int hm=func(n);
        return hm;
        
    }
}
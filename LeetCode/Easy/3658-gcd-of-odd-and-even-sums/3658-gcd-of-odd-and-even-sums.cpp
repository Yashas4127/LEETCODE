class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int gcdOfOddEvenSums(int n) {
        int oddSum = 0;
        int evenSum = 0;
        
        int currentOdd = 1;
        int currentEven = 2;
        
        
        for (int i = 0; i < n; i++) {
            oddSum += currentOdd;
            evenSum += currentEven;
            
            currentOdd += 2;  // Next odd number
            currentEven += 2; // Next even number
        }
        
        return gcd(oddSum, evenSum);
    }
};

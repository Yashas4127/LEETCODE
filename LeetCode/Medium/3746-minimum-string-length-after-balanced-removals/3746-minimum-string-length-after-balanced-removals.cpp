class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int countA=0;
        int countB=0;
        for(char ch:s){
            if(ch=='a'){
                countA++;
            }
            else{
                countB++;
            }
        }
        return abs(countB-countA);
    }
};
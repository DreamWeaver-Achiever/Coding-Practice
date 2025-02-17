// Link - https://leetcode.com/problems/integer-break/description/?envType=problem-list-v2&envId=dynamic-programming
public class IntegerBreak{
    class Solution {
        public int integerBreak(int n) {
            if(n == 2) return 1;
            if(n == 3) return 2;
    
            int prd = 1;
            while(n > 4){
                prd *=3;
                n -= 3;
            }
            prd *= n;
            return prd;
        }
    }
}
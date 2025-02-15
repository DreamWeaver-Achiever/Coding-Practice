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
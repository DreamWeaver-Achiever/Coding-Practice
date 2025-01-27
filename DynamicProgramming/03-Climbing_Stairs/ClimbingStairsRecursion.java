// link - https://leetcode.com/problems/climbing-stairs/description/
public class ClimbingStairsRecursion {
    class Solution {
        public int climbStairs(int n) {
            //  we can do this recusively, with each having two conditions to match the input whether it will take 1 step or it will take 2 steps, if we at any point get the valid sum to the input we return and add it to the total count.
            if ( n == 0) return 1; // if we reach the top of the stairs, we return 1
            if ( n < 1) return 0;
            return climbStairs(n - 1) + climbStairs(n - 2);
        }
        
    }
}

// Link - https://leetcode.com/problems/unique-paths/

public class UniquePathsDP {
    class Solution {
        public int uniquePaths(int m, int n) {
            int[][] dp = new int[m][n];
            for(int i = 0; i < dp.length; i++){
                dp[i][0] = 1; // only way to get to the 0th position given that we can only move down in 1
            }
            for(int i = 0; i < dp[0].length; i++){
                dp[0][i] = 1; // only way to get to the 0th position given that we can only move to our right is 1
            }
            for(int i = 1; i < dp.length; i++){
                for(int j = 1; j < dp[0].length; j++){
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j]; 
                }
            }
            return dp[m - 1][n -1];
        }
    }
}

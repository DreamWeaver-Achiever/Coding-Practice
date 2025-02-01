
// Link - https://leetcode.com/problems/minimum-path-sum/description/
public class MinimumPathSum {
    class Solution {
        public int minPathSum(int[][] grid) {
            int m = grid.length; 
            int n = grid[0].length;
    
            //initialize a dp
            int[][] dp = new int[m][n];
            dp[0][0] = grid[0][0];
            
            //first row will have the only direction that is straight and every cell indicates the sum taken to that cell, which is previous + current
            for(int i = 1; i < n; i++){
                dp[0][i] = dp[0][i - 1] + grid[0][i];
            }
    
            //first col will have the only direction that is straight down and every cell indicates the sum taken to that cell, which is previous + current
            for(int i = 1; i < m; i++){
                dp[i][0] = dp[i - 1][0] + grid[i][0];
            }
    
            // now the the middle cell will have the sum equals to whatever is min from up or down, will add it to the current cell
    
            for(int i = 1; i < m; i++){
                for(int j = 1; j < n; j++){
                    dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
            return dp[m - 1][n -1];
        }
    }
}

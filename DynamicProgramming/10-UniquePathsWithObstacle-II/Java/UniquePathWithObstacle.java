// Link - https://leetcode.com/problems/unique-paths-ii/
public class UniquePathWithObstacle {
    class Solution {
        public int uniquePathsWithObstacles(int[][] obstacleGrid) {
            int[][] dp = new int[obstacleGrid.length][obstacleGrid[0].length]; // dp[i][j] represents the unique paths to reach i,j from starting cell. 
            int m = obstacleGrid.length;
            int n = obstacleGrid[0].length;
            if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n -1] == 1){
                return 0; // no path to reach since we are blocked
            }
            dp[0][0] = 1; // initially we are there.
            
            //looping to the 1st row
            for(int i = 1; i < n; i++){
                if(obstacleGrid[0][i] == 1 ){
                    dp[0][i] = 0;
                }else{
                    dp[0][i] = dp[0][i-1];
                }
            }
    
            //looping to the 1st col
            for(int i = 1; i < m; i++){
                if(obstacleGrid[i][0] == 1 ){
                    dp[i][0] = 0;
                }else{
                    dp[i][0] = dp[i - 1][0];
                }
            }
    
            for(int i = 1; i < m; i++){
                for(int j = 1; j < n; j++){
                    if(obstacleGrid[i][j] != 1){
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }else{
                        dp[i][j] = 0; // encountered an obstacle so setting dp[i][j] = 0
                    }
                }
            }
            return dp[m-1][n-1];
        }
        
    }
}


// Link - https://leetcode.com/problems/minimum-falling-path-sum/
public class MinimumFallingPathSum {
    class Solution {
        public int minFallingPathSum(int[][] matrix) {
            int n = matrix.length;
            int[] dp = new int[n];  // Stores current row's minimum path sums
            int[] prev = new int[n]; // Stores previous row values
    
            // Initialize dp[] with the last row values
            for (int j = 0; j < n; j++) {
                prev[j] = matrix[n - 1][j];
            }
    
            // Process rows from bottom to top
            for (int i = n - 2; i >= 0; i--) {
                for (int j = 0; j < n; j++) {
                    // Get valid values from the row below
                    int down = prev[j]; // Directly below
                    int left = (j > 0) ? prev[j - 1] : Integer.MAX_VALUE;
                    int right = (j < n - 1) ? prev[j + 1] : Integer.MAX_VALUE;
    
                    // Update current dp[j] with min sum path
                    dp[j] = matrix[i][j] + Math.min(down, Math.min(left, right));
                }
                // Swap dp[] and prev[]
                int[] temp = dp;
                dp = prev;
                prev = temp;
            }
    
            // Return minimum from the first row
            int ans = Integer.MAX_VALUE;
            for (int num : prev) {
                ans = Math.min(ans, num);
            }
            return ans;
        }
    }    
}

import java.util.*;
public class Triangle {
    class Solution {
        public int minimumTotal(List<List<Integer>> triangle) {
            int[] dp = new int[triangle.size() + 1];
            // we will be using the botton-up dp traversal
            for(int i = triangle.size() - 1; i >= 0; i--){
                for(int j = 0; j < triangle.get(i).size(); j++){
                    dp[j] = Math.min(dp[j], dp[j+1]) + triangle.get(i).get(j);
                }
            }
            return dp[0];
        }
        
    }
}

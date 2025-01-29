// Link - https://leetcode.com/problems/house-robber/description/
public class HouseRobber {
    class Solution {
        public int rob(int[] nums) {
            int[] dp = new int[nums.length]; 
            if(nums.length == 1) return nums[0];
            dp[0]= nums[0];
            dp[1] = Math.max(nums[0], nums[1]); //dp[i] indicates the maximum amt robbed money til ith house.
            for(int i = 2; i < nums.length; i++){
                dp[i] = Math.max(dp[i - 1], nums[i] + dp[i - 2]); // dp[i] = Math.max(dp[i - 1] Not robbing the house, nums[i] + dp[i - 2] robbing the ith house.);
            }
            return dp[nums.length -1];
        }
    }
}

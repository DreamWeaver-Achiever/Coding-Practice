// Link - https://leetcode.com/problems/jump-game/description/?envType=problem-list-v2&envId=dynamic-programming
public class JumpGame {
    class Solution {
        public boolean canJump(int[] nums) {
            // T.C - O(N) S.C - O(1)
            int maxReach = 0;
            // max you can reach is idx + nums[i]
            for(int i = 0; i < nums.length; i++){
                if(i > maxReach) return false;
                maxReach = Math.max(maxReach, i + nums[i]);
            }
            return true;
        }
    }
}

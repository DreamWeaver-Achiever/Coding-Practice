import java.util.*;
public class FrogJump {
    // Link - https://leetcode.com/problems/frog-jump/
class Solution {
    HashMap<Integer, Integer> map = new HashMap<>();
    int[][] dp;
    public boolean canCross(int[] stones) {
        if(stones[1] - stones[0] != 1) return false; // since the first jump is always 1. 
       
        for(int i = 0; i < stones.length; i++){ // store the index of the stone in the map
            map.put(stones[i],i);
        }
        dp = new int[stones.length][stones.length];
        for (int[] row : dp){
            Arrays.fill(row, -1);
        }
        return solve(stones, 1, 1); // start from the second stone and jump 1

    }
    public boolean solve(int[] stones, int idx, int k){
        if(idx == stones.length - 1) return true; // reached the end
        if(dp[idx][k] != -1) return dp[idx][k] == 1; 

        boolean k0 = false;
        boolean kp = false;
        boolean k1 = false;

        if(map.containsKey(stones[idx] + k)){
            k0 = solve(stones, map.get(stones[idx] + k), k);  // can jump k moves 
        }
        if(k > 1 && map.containsKey(stones[idx] + k - 1)){
            kp = solve(stones, map.get(stones[idx] + k - 1), k - 1 ); // can jump k - 1 moves k need to be greater than 1
        }
        if(map.containsKey(stones[idx] + k + 1)){
            k1 = solve(stones, map.get(stones[idx] + k + 1), k + 1); // can jump k + 1 moves
        }
        dp[idx][k] = (k0 || k1 || kp) ? 1 : 0; // if any of the 3 is true then return true else false
        return dp[idx][k] == 1;
    }
}
}

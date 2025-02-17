/*
Platform : Leetcode
Problem Link: https://leetcode.com/problems/minimum-sideway-jumps/description/
Problem Statement : 
There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.

*/

/*
Time Complexity -> O(3 * n) which simplifies to O(n).
Space Complexity -> O(n).
*/

class Solution {
    public:
        int minSideJumps(vector<int>& obstacles) {
            // Step - 1
            vector<vector<int>> dynamicArray(4, vector<int>(obstacles.size(), 0));
            int n = obstacles.size() - 1; // as obstacles+1 is the length
            // Base cases
            dynamicArray[0][n] = 0;
            dynamicArray[1][n] = 0;
            dynamicArray[2][n] = 0;
            dynamicArray[3][n] = 0;
    
            // Sideway jump logic
            for (int currentPosition = n - 1; currentPosition >= 0; currentPosition--) {
                for (int currentLane = 1; currentLane <= 3; currentLane++) {
                    if (obstacles[currentPosition + 1] != currentLane) {
                        dynamicArray[currentLane][currentPosition] = dynamicArray[currentLane][currentPosition+1];
                    } else {
                        // sideways jump
                        int ans = 1e9;
                        for (int i = 1; i <= 3; i++) {
                            if ((currentLane != i) && (obstacles[currentPosition] != i)) {
                                ans = min(ans, 1 + dynamicArray[i][currentPosition+1]);
                            }
                        }
                        dynamicArray[currentLane][currentPosition] = ans;
                    }
                }
            } 
            return min(dynamicArray[2][0], min(1+dynamicArray[1][0], 1+dynamicArray[3][0]));
        }
    }
    ;
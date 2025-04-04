/*
Platform -> Leetcode
ProblemLink -> https://leetcode.com/problems/min-cost-climbing-stairs/
Problem statement:
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/

/*
Logic -> 
[1] Jana toh nth stair par hi hai lekin isme aur ek condition add hojayegi ki calculate the minimum cost ti reach on nth stair.
[2] Also, you can start from 0th stair or from 1st stair.
[3] We have to pay cost then only we can move ahead by 1 or 2 stairs.
[4] Also, once we reach on the last stait we won't need to pay any cost.

f(n) = cost[n] + min(f(n-1), f(n-2))

*/

class Solution {
public:
    int calculateMinimumCost(vector<int>& cost, int totalStairs) {
        //Base Case - 1
        if(totalStairs == 0) {
            return cost[0];
        } 

        //Base Case - 2
        if(totalStairs == 1) {
            return cost[1];
        }

        return cost[totalStairs] + min(calculateMinimumCost(cost, totalStairs-1), calculateMinimumCost(cost, totalStairs-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int totalStairs = cost.size();
        return min(calculateMinimumCost(cost, totalStairs-1), calculateMinimumCost(cost, totalStairs-2));
    }
};
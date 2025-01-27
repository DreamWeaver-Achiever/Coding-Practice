/*
The only difference between this problem and '02- Count Ways To Reach The N-th Stairs-Code360' is in the mod value. Here, we have to take it as 10000000000 to pass all test cases.

Platform - Leetcode
Link - https://leetcode.com/problems/climbing-stairs/description/
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/
#define MOD 10000000000
class Solution {
public: 
long long calculateStairs(vector<long long>& dynamicArray, int currentStair, int totalNumberOfStairs) {
    // Base case
    if (currentStair > totalNumberOfStairs) {
        return 0;
    }
    if (currentStair == totalNumberOfStairs) {
        return 1;
    }

    // Check if the result is already stored in the dynamic array
    if (dynamicArray[currentStair] != -1) {
        return dynamicArray[currentStair];
    }

    // Calculate the result
     dynamicArray[currentStair] = (calculateStairs(dynamicArray, currentStair + 1, totalNumberOfStairs)+ 
                                calculateStairs(dynamicArray, currentStair + 2, totalNumberOfStairs));

    return dynamicArray[currentStair]%MOD ;
}

int climbStairs(int totalNumberOfStairs) {
    // Declare dynamic array with size n+1 and all elements = -1.
    vector<long long> dynamicArray(totalNumberOfStairs + 1, -1); 
    return calculateStairs(dynamicArray, 0, totalNumberOfStairs);
}

};
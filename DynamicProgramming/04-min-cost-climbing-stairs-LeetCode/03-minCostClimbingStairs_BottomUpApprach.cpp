/* 
Time Complexity -> O(n), where n is the size of the cost array.
Space Complexity -> O(n), The code uses a dynamicArray of size n to store the minimum costs for each step.  
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int totalStairs = cost.size();
        //Step-1 Declare an array with size totalStairs.
        vector<int>dynamicArray(totalStairs);

        //Step-2 Base Cases
        dynamicArray[0] = cost[0];
        dynamicArray[1] = cost[1];

        //Step-3 for loop from totalStairs=2 to totalStairs-1
        for(int i=2; i<totalStairs; i++) {
            dynamicArray[i] = cost[i] + min(dynamicArray[i-1], dynamicArray[i-2]);

        }
        return min(dynamicArray[totalStairs-1], dynamicArray[totalStairs-2]);
    }
};
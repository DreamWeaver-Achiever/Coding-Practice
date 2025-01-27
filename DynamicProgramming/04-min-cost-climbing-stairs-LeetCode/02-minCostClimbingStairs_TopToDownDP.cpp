/* Time Complexity -> O(n), where n is the number of stairs. This is because each step's minimum cost is calculated only once and stored in the dynamicArray.
   Space Complexity: O(n) to store the dynamicArray + O(n) for storing constants.
*/

class Solution {
public:
    int calculateMinimumCost(vector<int>& cost, int totalStairs, vector<int>& dynamicArray) {
        //Base Case - 1
        if(totalStairs == 0) {
            return cost[0];
        } 

        //Base Case - 2
        if(totalStairs == 1) {
            return cost[1];
        }

        //Step -2 -> Check if element != -1 i.e. the check if result is already computed or not.
        if(dynamicArray[totalStairs] != -1) {
            return dynamicArray[totalStairs];
        }

        //Step - 3 -> Recursive way i.e. element == -1 so result is not yet computed.
        return cost[totalStairs] + min(calculateMinimumCost(cost, totalStairs-1, dynamicArray), calculateMinimumCost(cost, totalStairs-2, dynamicArray));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int totalStairs = cost.size();
        //Step - 1 Declare an array with size totalStairs+1 and each element equal to -1.
        vector<int>dynamicArray(totalStairs+1, -1);
        return min(calculateMinimumCost(cost, totalStairs-1, dynamicArray), calculateMinimumCost(cost, totalStairs-2, dynamicArray));
    }
};
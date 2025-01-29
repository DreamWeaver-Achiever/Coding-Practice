
/*
Time Complexity -> O(n)
Space Complexity -> O(1)
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int totalStairs = cost.size();

        //Base Case
        if (totalStairs <= 1) {
            return 0; // No cost for 0 or 1 steps
        }

        //Step-1 Everytime i is dependent on i-1 and i-2.
        int previousCost1 = cost[1];
        int previousCost2 = cost[0];

        //Step-2for loop from totalStairs=2 to totalStairs-1
        for(int i=2; i<totalStairs; i++) {
            int currentCost = cost[i] + min(previousCost1, previousCost2);
            //Shift logic forward.
            previousCost2 = previousCost1;
            previousCost1 = currentCost;

        }
        return min(previousCost1, previousCost2);
    }
};
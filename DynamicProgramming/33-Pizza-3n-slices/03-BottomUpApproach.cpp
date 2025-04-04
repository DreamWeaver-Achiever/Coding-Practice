/*
There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.
*/

//Problem Link -> https://leetcode.com/problems/pizza-with-3n-slices/description/

/*
Time Complexity -> O(n^2).
Space Complexity -> O(n^2).
*/

class Solution {
    public:
        int maxSizeSlices(vector<int>& slices) {
            int k = slices.size();
            vector<vector<int>> dp1(k+2, vector<int>(k+2, 0)); //Have to take 'k+2' to avoid index out of bound.
            vector<vector<int>> dp2(k+2, vector<int>(k+2, 0)); //Have to take 'k+2' to avoid index out of bound.
    
            for(int index=k-2; index>=0; index--) {
                for(int n=1; n<=k/3; n++) {
                    int take = slices[index] + dp1[index+2][n-1];
                    int notTake = 0+dp1[index+1][n];
                    dp1[index][n] = max(take, notTake);
                }
            } 
            int case1=dp1[0][k/3];
            for(int index=k-1; index>=1; index--) {
                for(int n=1; n<=k/3; n++) {
                    int take = slices[index]+dp2[index+2][n-1];
                    int notTake = 0+dp2[index+1][n];
                    dp2[index][n] = max(take, notTake);
                }
            }
            int case2 = dp2[1][k/3];
            return max(case1, case2);
        }
    };
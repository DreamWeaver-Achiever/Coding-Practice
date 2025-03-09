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
Space Complexity -> O(n).
*/

class Solution {
    public:
        int maxSizeSlices(vector<int>& slices) {
            //Dependency of three rows -> [index+2], [index+1], [n-1] so take it as prev1, curr1, next1 for dp1;
            //Dependency of three rows -> [index+2], [index+1], [n-1] so take it as prev2, curr2, next2 for dp2;
    
            int k = slices.size();
    
            vector<int> prev1(k+2, 0);
            vector<int> curr1(k+2, 0);
            vector<int> next1(k+2, 0);
    
            vector<int> prev2(k+2, 0);
            vector<int> curr2(k+2, 0);
            vector<int> next2(k+2, 0);
    
            for(int index=k-2; index>=0; index--) { 
                for(int n=1; n<=k/3; n++) {
                    int take=slices[index]+next1[n-1];
                    int notTake = 0 + curr1[n];
    
                    prev1[n] = max(take, notTake);
                } 
                next1 = curr1; 
                curr1 = prev1;
            } 
            int case1 = curr1[k/3]; 
    
            for(int index=k-1; index>=1; index--) {
                for(int n=1; n<=k/3; n++) {
                    int take = slices[index]+next2[n-1];
                    int notTake = 0 + curr2[n];
    
                    prev2[n] = max(take, notTake);
                } 
                next2 = curr2; 
                curr2 = prev2;
            } 
            int case2 = curr2[k/3];
            return max(case1, case2);
    
        }
    };
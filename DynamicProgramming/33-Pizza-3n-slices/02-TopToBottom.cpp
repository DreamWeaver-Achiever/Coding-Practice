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
Time Complexity -> O(n).
Space Complexity -> O(n^2).
*/

class Solution {
    public:
        int calculateMySlices(int index, int endIndex, vector<int>& slices, int mySlices, vector<vector<int>>& dynamicArray) {
            //Base Cases -> [1] If mySlices=0 i.e. you have already had the pizza slices. [2] Your index is went out of the slices.
            if(mySlices==0 || index>endIndex) { 
                return 0;
            } 
    
            //Step-2 -> Check if element of a dp array != -1 then element is already calculated so, return it as it is.
            if(dynamicArray[index][mySlices] != -1) {
                return dynamicArray[index][mySlices];
            }
    
            int eat = slices[index] + calculateMySlices(index+2, endIndex, slices, mySlices-1, dynamicArray);
            int notEat = 0 + calculateMySlices(index+1, endIndex, slices, mySlices, dynamicArray);
    
            return dynamicArray[index][mySlices] = max(eat, notEat);
        }
        int maxSizeSlices(vector<int>& slices) {
            int totalSlices = slices.size();
            int mySlices = totalSlices/3;
    
            vector<vector<int>> dpForCase1(totalSlices, vector<int>(totalSlices, -1));
            int case1 = calculateMySlices(0, totalSlices-2, slices, mySlices, dpForCase1);
            vector<vector<int>> dpForCase2(totalSlices, vector<int>(totalSlices, -1));
            int case2 = calculateMySlices(1, totalSlices-1, slices, mySlices, dpForCase2);
    
            return max(case1, case2);
        }
    };
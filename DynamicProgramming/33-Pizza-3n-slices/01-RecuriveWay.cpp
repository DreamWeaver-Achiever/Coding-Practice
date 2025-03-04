/*
There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.
*/

/*
Time Complexity -> O(2^n).
Space Complexity -> O(n).
*/

class Solution {
    public:
        int calculateMySlices(int index, int endIndex, vector<int>& slices, int mySlices) {
            //Base Cases -> [1] If mySlices=0 i.e. you have already had the pizza slices. [2] Your index is went out of the slices.
            if(mySlices==0 || index>endIndex) { 
                return 0;
            } 
    
            int eat = slices[index] + calculateMySlices(index+2, endIndex, slices, mySlices-1);
            int notEat = 0 + calculateMySlices(index+1, endIndex, slices, mySlices);
    
            return max(eat, notEat);
        }
        int maxSizeSlices(vector<int>& slices) {
            int totalSlices = slices.size();
            int mySlices = totalSlices/3;
    
            int case1 = calculateMySlices(0, totalSlices-2, slices, mySlices);
            int case2 = calculateMySlices(1, totalSlices-1, slices, mySlices);
    
            return max(case1, case2);
        }
    };
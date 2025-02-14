/*
Platform -> Leetcode.
Problem Link -> https://leetcode.com/problems/reducing-dishes/description/
Problem Statement -> 
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
*/
/*
Time Complexity -> O(n^2)
Space Complexity -> O(n^2).
*/

class Solution {
    public:
        int calculateMaxSatisfaction(vector<int>& satisfaction, int index, int time, vector<vector<int>>& dynamicArray) {
            //Base case
            if(index==satisfaction.size()) {
                return 0;
            } 
    
            //Step-2 -> Check if element of an array != -1 i.e. the case where result is already computed.
            if(dynamicArray[index][time] != -1) {
                return dynamicArray[index][time];
            } 
    
            //Step-3 -> If element is not already computed then calculate it recursively.
            int include = satisfaction[index]*(time+1)+calculateMaxSatisfaction(satisfaction, index+1, time+1, dynamicArray);
            int exclude = 0+calculateMaxSatisfaction(satisfaction, index+1, time, dynamicArray);
    
            dynamicArray[index][time] = max(include, exclude);
            return dynamicArray[index][time];
    
        }
        int maxSatisfaction(vector<int>& satisfaction) {
            //sort the vector
            sort(satisfaction.begin(), satisfaction.end());
    
            //Step-1 -> Create a vector with length = n+1 and each_element = -1. 
            int n = satisfaction.size();
            vector<vector<int>> dynamicArray(n+1, vector<int>(n+1, -1));
            return calculateMaxSatisfaction(satisfaction, 0, 0, dynamicArray);
        }
    };
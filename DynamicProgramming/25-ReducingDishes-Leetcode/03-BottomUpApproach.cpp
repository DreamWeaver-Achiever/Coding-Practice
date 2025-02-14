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
        int maxSatisfaction(vector<int>& satisfaction) {
            //sort the vector.
            sort(satisfaction.begin(), satisfaction.end()); 
    
            int n = satisfaction.size();
            //Declare 2D-array with lenght = n+1, elements=0;
            vector<vector<int>> dynamicArray(n+1, vector<int>(n+1, 0));
            for(int index=n-1; index>=0; index--) {
                for(int time=index; time>=0; time--) {
                    int include = satisfaction[index]*(time+1) + dynamicArray[index+1][time+1];
                    int exclude = dynamicArray[index+1][time];
                    dynamicArray[index][time]=max(include, exclude);
                }
            } 
            return dynamicArray[0][0];
        }
    };
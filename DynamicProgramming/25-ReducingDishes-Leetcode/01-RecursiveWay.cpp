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
Time Complexity -> O(n<Supremum>2</Supremum>)
Space Complexity -> O(n).
*/
class Solution {
    public:
        int calculateMaxSatisfaction(vector<int>& satisfaction, int index, int time) {
            //Base case
            if(index==satisfaction.size()) { //i input array se bahar nikal gaya.
            return 0;
            } 
    
            int include = satisfaction[index]*(time+1) + calculateMaxSatisfaction(satisfaction, index+1, time+1);
            int exclude = 0+calculateMaxSatisfaction(satisfaction, index+1, time);
    
            return max(include, exclude);
    
        }
        int maxSatisfaction(vector<int>& satisfaction) {
            //sort the vector
            sort(satisfaction.begin(), satisfaction.end());
            return calculateMaxSatisfaction(satisfaction, 0, 0);
        }
    };
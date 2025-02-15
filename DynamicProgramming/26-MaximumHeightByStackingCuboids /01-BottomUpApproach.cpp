/*
Pltform : Leetcode
Problem Link: https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/
Problem Statement :
Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.
*/

/*
Time Complexity -> O(n^2).
Space Complexity -> O(n).
*/
class Solution {
    public:
        bool checks(vector<int>& base, vector<int>& newBox) {
            if(newBox[0]<=base[0] && newBox[1]<=base[1] && newBox[2]<=base[2]) {
                return true;
            } else {
                return false;
            }
        } 
    
        int maxHeight(vector<vector<int>>& cuboids) {
            //Step-1 -> Sort each row.
            for(auto &a: cuboids) {
                sort(a.begin(), a.end());
            } 
    
            //Step-2 -> Sort all cuboids on the basis of width and length.
            sort(cuboids.begin(), cuboids.end());
    
            //Step-3 -> Use Longest increasing subsequence logic
            int n = cuboids.size();
           vector<int> currentRow(n+1, 0);
            vector<int> nextRow(n+1, 0);
    
            for(int curr = n-1; curr>=0; curr--) {
                for(int prev = curr-1; prev>=-1; prev--) {
                    
                    int include =0; 
                    if(prev == -1 || checks(cuboids[curr], cuboids[prev])) 
                    include = cuboids[curr][2] + nextRow[curr+1];
    
                    int exclude = 0 + nextRow[prev+1];
    
                    currentRow[prev+1] = max(include, exclude);
                } 
                nextRow=currentRow;
            } 
            return nextRow[0];
        }
    };
/*
Platform -> LeetCode
Problem Link -> https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
Problem Statment -> 
Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

*/

/* Complexities ->  
Time Complexity -> O(n).
Space Complexity -> O(n).
*/

class Solution {
    public:
        int longestSubsequence(vector<int>& arr, int difference) {
            unordered_map<int, int> dp;
            int maxLength = 0;
    
            for (int num : arr) {
                int prev = num - difference;
                if (dp.find(prev) != dp.end()) {
                    dp[num] = dp[prev] + 1;
                } else {
                    dp[num] = 1;
                }
                maxLength = max(maxLength, dp[num]);
            }
            return maxLength;
        }
    };
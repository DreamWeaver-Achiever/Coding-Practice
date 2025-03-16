/*
Platform -> Code360
Problem Link -> https://www.naukri.com/code360/problems/longest-consecutive-sequence_759408?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true&practice_topic%5B%5D=Arrays&leftPanelTabValue=PROBLEM
Problem Statment -> 
You are given an unsorted array/list 'ARR' of 'N' integers. Your task is to return the length of the longest consecutive sequence.

The consecutive sequence is in the form ['NUM', 'NUM' + 1, 'NUM' + 2, ..., 'NUM' + L] where 'NUM' is the starting integer of the sequence and 'L' + 1 is the length of the sequence.

Note:

If there are any duplicates in the given array we will count only one of them in the consecutive sequence.
For example-
For the given 'ARR' [9,5,4,9,10,10,6].

Output = 3
The longest consecutive sequence is [4,5,6].
Follow Up:
Can you solve this in O(N) time and O(N) space complexity?
*/

/* Complexities ->  
Time Complexity -> O(n).
Space Complexity -> O(n).
*/

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    if (n == 0) {
        return 0;
    }

    std::unordered_set<int> s(arr.begin(), arr.end());
    int longestStreak = 0;

    for (int num : s) {
        if (s.find(num - 1) == s.end()) { // Check if 'num' is the start of a sequence
            int currentNum = num;
            int currentStreak = 1;

            while (s.find(currentNum + 1) != s.end()) {
                currentNum++;
                currentStreak++;
            }

            longestStreak = std::max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}
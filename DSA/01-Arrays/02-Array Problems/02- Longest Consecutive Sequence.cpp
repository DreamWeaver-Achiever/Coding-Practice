//Problem: https://www.naukri.com/code360/problems/longest-consecutive-sequence_759408?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true&practice_topic%5B%5D=Arrays&attempt_status=COMPLETED
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
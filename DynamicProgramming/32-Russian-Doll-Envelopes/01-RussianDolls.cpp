/*
Problem Link: https://leetcode.com/problems/russian-doll-envelopes/description/
Problem Statement:
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.
*/

/* 
Time Complexity -> O(n log n)
Space Complexity -> O(n)
*/

class Solution {
    public:
        int maxEnvelopes(vector<vector<int>>& envelopes) {
            if (envelopes.empty()) {
            return 0;
        }
    
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // Descending height if widths are equal
            }
            return a[0] < b[0]; // Ascending width
        });
    
        vector<int> heights;
        for (const auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }
    
        vector<int> tails;
        for (int height : heights) {
            if (tails.empty() || height > tails.back()) {
                tails.push_back(height);
            } else {
                auto it = lower_bound(tails.begin(), tails.end(), height);
                *it = height;
            }
        }
    
        return tails.size();
        }
    };
//Problem Link -> https://www.naukri.com/code360/problems/sort-odd-even_18711664?challengeSlug=month-of-code-challenge-1&interviewProblemRedirection=true&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
void sortOddEven(vector<int>& nums){
    // Write your code here
    vector<int> even;
    vector<int> odd;
    for(int i=0; i<=nums.size()-1; i++) {
        if(nums[i]%2==0) {
            even.push_back(nums[i]);
        } else {
            odd.push_back(nums[i]);
        }
    } 
    sort(even.begin(), even.end());
    sort(odd.rbegin(), odd.rend());
    nums.clear();
    nums.insert(nums.end(), odd.begin(), odd.end()); 
    nums.insert(nums.end(), even.begin(), even.end()); // Append sorted even numbers

}
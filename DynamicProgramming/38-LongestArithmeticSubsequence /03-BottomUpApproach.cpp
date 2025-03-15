/*
Platform -> gfg
Problem Link -> https://www.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1
Problem Statment -> 
Given an array arr[] of sorted and distinct positive integers. The task is to find the length of the longest arithmetic progression in a given array.

Note: A sequence seq is an arithmetic progression if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
*/

/* Complexities ->  
Time Complexity -> O(n^2).
Space Complexity -> O(n^2).
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        int n = arr.size();
        //Base case
        if(n<=2) {
            return n;
        }
        int ans=0;
        unordered_map<int, int> dp[n+1];
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int diff = arr[i]-arr[j];
                int count = 1;
                //Check if answer is already present
                if(dp[j].count(diff)) {
                    count = dp[j][diff];
                }
                dp[i][diff]=1+count;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.lengthOfLongestAP(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
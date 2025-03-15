/*
Platform -> gfg
Problem Link -> https://www.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1
Problem Statment -> 
Given an array arr[] of sorted and distinct positive integers. The task is to find the length of the longest arithmetic progression in a given array.

Note: A sequence seq is an arithmetic progression if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
*/

/* Complexities ->  
Time Complexity -> O(n^3).
Space Complexity -> O(n).
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
   int calculateLongestAP(int index, int diff,vector<int>& arr) {
       //Backward check
       if(index<0) {
           return 0;
       } 
       int ans=0;
       for(int j=index-1;j>=0; j--) {
           if(arr[index]-arr[j]==diff) {
               ans = max(ans, 1+calculateLongestAP(j, diff, arr));
           }
       } 
       return ans;
   }
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        int n = arr.size();
        //Base case
        if(n<=2) {
            return n;
        }
        int ans=0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                ans = max(ans, 2+calculateLongestAP(i, arr[j]-arr[i], arr));
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
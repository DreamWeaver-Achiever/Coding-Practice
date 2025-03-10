/*
Platform: GFG
Problem Link: https://www.geeksforgeeks.org/problems/dice-throw5349/1
Problem Statement: 
Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.
*/

/*
Time Complexity: O(dices * target).
Space Complexity: O(dices * target).
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long calculateNoOfWays(int faces, int dices, int target, vector<vector<long long int>>& dynamicArray) {
        // code here
        //Base cases
        if(target<0) {
            return 0;
        } else if(target==0  && dices!=0) {
            return 0;
        } else if(target !=0 && dices==0) {
            return 0;
        } else if(target==0 && dices==0) {
            //Eat 5-Star, do nothing is the only single way.
            return 1;
        } 
        
        //Step-2 -> If elements of dynamicArray[dice][target] != -1, it means elements are already calculated.
        if(dynamicArray[dices][target] != -1) {
            return dynamicArray[dices][target];
        }
        
        //Step-3 -> If elements of dynamicArray[dice][target] == -1, it means elements are not yet calculated so, compute it recursively.
        long long ans=0;
        for(int i=1; i<=faces; i++) {
            ans = ans + calculateNoOfWays(faces, dices-1, target-i, dynamicArray);
        } 
        dynamicArray[dices][target] = ans;
        return dynamicArray[dices][target];
    }
    int noOfWays(int faces, int dices, int target) {
        // code here
        //Step-1 -> Declare 2D vector with elements -1.
        vector<vector<long long int>> dynamicArray(dices+1, vector<long long int>(target+1, -1));
        return calculateNoOfWays(faces, dices, target, dynamicArray);
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        int m, n, x;
        cin >> m >> n >> x;

        Solution ob;
        cout << ob.noOfWays(m, n, x) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
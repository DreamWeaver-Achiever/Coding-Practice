/*
Platform: GFG
Problem Link: https://www.geeksforgeeks.org/problems/dice-throw5349/1
Problem Statement: 
Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.
*/

/*
Time Complexity: exponential.
Space Complexity: O(dices).
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int noOfWays(int faces, int dices, int target) {
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
        long long ans=0;
        for(int i=1; i<=faces; i++) {
            ans = ans + noOfWays(faces, dices-1, target-i);
        } 
        return ans;
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
/*
Platform -> gfg
Problem Link -> https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1
Problem Statement -> Given a number n, find the minimum number of perfect squares (square of an integer) that sum up to n. 

Examples:

Input: n = 100
Output: 1
Explanation: 10 * 10 = 100
Input: n = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6 
Expected Time Complexity: O(n * sqrt(n))
Expected Space Complexity: O(n)

Constraints:
1 <= n <= 104


*/
/*
Time Complexity -> O(n * sqrt(n))
Space Complexity -> O(n)
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public: 
    int findSquares(int n, vector<int>& dynamicArray) {
        //Base case 
        if(n == 0) {
            return 0;
        }
        
        //Step - 2 -> Check if dynamicArray[n] != -1 i.e. the case where result is already computed.
        if(dynamicArray[n] != -1) {
            return dynamicArray[n];
        }
        
        //Step - 3 -> Check if dynamicArray[n] == -1 i.e. the case where result is not yet computed and need to compute it recursively.
        int ans = n;
        for(int i=1; i*i<=n; i++) {
            int temp = i*i;
            ans = min(ans, 1+findSquares(n-temp, dynamicArray));
        }
        dynamicArray[n] = ans;
        return dynamicArray[n];
    }
    int MinSquares(int n) {
        vector<int> dynamicArray(n+1, -1);
        return findSquares(n, dynamicArray);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
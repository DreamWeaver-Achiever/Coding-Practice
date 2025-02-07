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
Time Complexity -> O(n * sqrt(n)).
Space Complexity ->  O(n).
*/


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public: 
    int MinSquares(int n) { 
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j*j<=n; j++) { 
                int temp = j*j;
                if((i-temp) >= 0) {
                dp[i] = min(dp[i], 1+dp[i-temp]); 
                }
                
            }
        }
        return dp[n];
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
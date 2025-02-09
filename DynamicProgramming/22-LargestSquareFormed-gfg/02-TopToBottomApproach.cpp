/*
Platform: gfg
Problem Link: https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
Problem Statement:
Largest square formed in a matrix
Given a binary matrix mat, find out the maximum length of a side of a square sub-matrix with all 1s.

Examples:

Input: mat = [[0, 1, 1, 0, 1], 
              [1, 1, 0, 1, 0],
              [0, 1, 1, 1, 0],
              [1, 1, 1, 1, 0],
              [1, 1, 1, 1, 1],
              [0, 0, 0, 0, 0]]
Output: 3
Explanation: 

The maximum length of a side of the square sub-matrix is 3 where every element is 1.
Input: mat = [[1, 1], 
              [1, 1]]
Output: 2
Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
Input: mat = [[0, 0], 
              [0, 0]]
Output: 0
Explanation: There is no 1 in the matrix.
Constraints:
1 ≤ mat.size(), mat[i].size() ≤ 500
0 ≤ mat[i][j] ≤ 1 


*/

/*
Complexities:
Time Complexity -> O(n^2).
Space Complexity -> O(n^2).
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    static int calculateMaximumSquare(vector<vector<int>>&matrix, int i, int j, int &maxi, vector<vector<int>>&dynamicArray) {
        //Base case
        if((i>=matrix.size()) || (j>=matrix[0].size())) {
            return 0;
        } 
        
        //Step-2 -> Check if element of an array is != -1 i.e. result is already computed. 
        if(dynamicArray[i][j] != -1) {
            return dynamicArray[i][j];
        } 
        
        //Step-3 -> if element of an array is == -1 then result is not yet computed. 
        int right = calculateMaximumSquare(matrix, i, j+1, maxi, dynamicArray);
        int diagonal = calculateMaximumSquare(matrix, i+1, j+1, maxi, dynamicArray); 
        int down = calculateMaximumSquare(matrix, i+1, j, maxi, dynamicArray); 
        
        if(matrix[i][j]==1) {
            dynamicArray[i][j] = 1+min(right, min(diagonal, down));
            maxi = max(maxi, dynamicArray[i][j]);
            return dynamicArray[i][j];
        } else {
            return dynamicArray[i][j]=0;
        }
    }
    int maxSquare(vector<vector<int>>& matrix) {
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi=0;
        //Step-1 -> Create 2D dynamicArray.
        vector<vector<int>> dynamicArray(n, vector<int>(m, -1));
        calculateMaximumSquare(matrix, 0, 0, maxi, dynamicArray); 
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(mat) << "\n"
             << "~\n";
    }
    return 0;
}
// } Driver Code Ends
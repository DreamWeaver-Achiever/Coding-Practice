//Problem Link -> https://www.naukri.com/code360/contests/striver-array-contest/9755146/problems/8186?leftPanelTabValue=PROBLEM
/*
Problem Satement ->
You are given a square matrix of non-negative integers of size 'N x N'. Your task is to rotate that array by 90 degrees in an anti-clockwise direction without using any extra space.

For example:

For given 2D array :

    [    [ 1,  2,  3 ],
         [ 4,  5,  6 ],
         [ 7,  8,  9 ]  ]

After 90 degree rotation in anti clockwise direction, it will become:

    [   [ 3,  6,  9 ],
        [ 2,  5,  8 ],
        [ 1,  4,  7 ]   ]
*/
#include <bits/stdc++.h> 
void inplaceRotate(vector<vector<int>> &inputArray)
{
    // Write your code here.
    int n = inputArray.size();
    // Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            std::swap(inputArray[i][j], inputArray[j][i]);
        }
    }

    // Reverse each column
    for (int j = 0; j < n; j++) {
        for (int i = 0, k = n - 1; i < k; i++, k--) {
            std::swap(inputArray[i][j], inputArray[k][j]);
        }
    }
}
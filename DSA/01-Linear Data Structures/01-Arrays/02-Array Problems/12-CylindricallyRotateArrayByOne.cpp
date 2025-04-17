//Problem link -> https://www.naukri.com/code360/contests/striver-array-contest/9755146/problems/9977?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
void rotate(vector<int>& arr, int n) {
    // Write your code here
    int last = arr[n-1];
    for(int i=arr.size()-1; i>0; i--) {
        arr[i]= arr[i-1];
    }
    arr[0] = last;
}
//Problem Link -> https://www.naukri.com/code360/problems/reverse-the-array_1262298?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true&practice_topic%5B%5D=Arrays&attempt_status=COMPLETED
#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
    // Write your code here. 
    
    int len = arr.size(); 
    int start =m+1; 
    int end = len-1;
    while(start<end) { 
        swap(arr[start], arr[end]); 
        start++;
        end--; 
        
    } 
}
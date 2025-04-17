//Problem Link -> https://www.naukri.com/code360/problems/sort-0-1-2_631055?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true&practice_topic%5B%5D=Arrays&attempt_status=COMPLETED

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here 
   int low = 0, high = n - 1, mid = 0;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}
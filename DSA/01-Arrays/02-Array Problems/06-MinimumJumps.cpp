//Problem Link -> https://www.naukri.com/code360/problems/minimum-jumps_1062693?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true&practice_topic%5B%5D=Arrays&attempt_status=COMPLETED

#include <vector>
#include <cmath> 
#include <algorithm> // Needed for std::max

int minimumJumps(vector<int> &arr, int n)
{
    // write your code here
    //Base case
    if(n==1) {
        return 0;
    }
    int max=0;
    int maxRange=0;
    int count =0;
    for(int i=0; i<n; i++) {
        max = std::max(max, i+arr[i]);
        if(maxRange==i) {
            maxRange=max;
            count++;
        }
        if(maxRange>=n-1){
            return count;
        }
    } 
    return -1;
}
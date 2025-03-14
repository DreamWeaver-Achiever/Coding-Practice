/*
Platform -> code360.
Problem Link -> https://www.naukri.com/code360/problems/minimum-jumps_1062693?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true&practice_topic%5B%5D=Dynamic%20Programming&leftPanelTabValue=PROBLEM
Problem Statement -> 
Bob lives with his wife in a city named Berland. Bob is a good husband, so he goes out with his wife every Friday to ‘Arcade’ mall.

‘Arcade’ is a very famous mall in Berland. It has a very unique transportation method between shops. Since the shops in the mall are laying in a straight line, you can jump on a very advanced trampoline from the shop i, and land in any shop between (i) to (i + Arr[i]), where Arr[i] is a constant given for each shop.

There are N shops in the mall, numbered from 0 to N-1. Bob's wife starts her shopping journey from shop 0 and ends it in shop N-1. As the mall is very crowded on Fridays, unfortunately, Bob gets lost from his wife. So he wants to know, what is the minimum number of trampoline jumps from shop 0 he has to make in order to reach shop N-1 and see his wife again. If it is impossible to reach the last shop, return -1.
*/

/*
Time Complexity: O(n).
Space Complexity: O(1).
*/
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
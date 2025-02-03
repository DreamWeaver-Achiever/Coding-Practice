/*
Platform -> Code360
Problem Link -> https://www.naukri.com/code360/problems/house-robber_839733?leftPanelTab=0
Problem statement:
Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden.



All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.



You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.



Note:
It is possible for Mr. X to rob the same amount of money by looting two different sets of houses. Just print the maximum possible robbed amount, irrespective of sets of houses robbed.


For example:
(i) Given the input array arr[] = {2, 3, 2} the output will be 3 because Mr X cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses. So, he’ll rob only house 2 (money = 3)

(ii) Given the input array arr[] = {1, 2, 3, 1} the output will be 4 because Mr X rob house 1 (money = 1) and then rob house 3 (money = 3).

(iii) Given the input array arr[] = {0} the output will be 0 because Mr. X has got nothing to rob.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 5 x 10 ^ 3
1 <= ARR[i] <= 10 ^ 9

Time limit: 1 sec.
Sample Input 1:
3
1
0
3
2 3 2
4
1 3 2 1
Sample Output 1:
0
3
4
Explanation of Input 1:
(i) Mr. X has only one house to rob, but with no money.

(ii) Mr. X cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses (remember, it’s a circular street). So, he’ll rob only house 2 (money = 3) with a maximum value

(iii) Mr. X will get maximum value when he robs house 2 (money = 3) and then robs house 4 (money = 1) i.e. 4 units of money.
Sample Input 2:
3
5
1 5 1 2 6
3
2 3 5
4
1 3 2 0
Sample Output 2:
11
5
3
*/

/* Time Complexity -> O(n).
Space Complexity -> O(n).
*/
#include <bits/stdc++.h> 

long long int maximumRobbery(vector<int> &arrayList){
    // Write your code here.
    long long int totalElements = arrayList.size();

    //declare two variables for base values 
    long long int previous1 = arrayList[0];
    long long int previous2 = 0;

    //Convert recursive call logic of top-down approach into tabulation using for loop.
    for(int i=1; i<totalElements; i++) {
        long long int include = previous2+arrayList[i];
        long long int exclude = previous1;
        long long int ans = max(include, exclude);
        previous2 = previous1;
        previous1 = ans;

    } 
    return previous1;
}

long long int houseRobber(vector<int>& houses)
{
    // Write your code here.
    int totalHouses = houses.size();

        //if only one house is present, then return that single house.
        if(totalHouses == 1) { 
            return houses[0];
        }

        //Here, Houses are arraged in the circular colony so; we need to check two cases -> [1] if starting from 1, then don't take last house into account [2] if starting from last house then don't consider first house into account. Anyways, we are receiving input in the array format.

        //Declare two vectors to handle these two cases.
        vector<int> firstHouseSeries, lastHouseSeries;
        for(int i=0; i<totalHouses; i++) {
            if(i != totalHouses-1) {
                firstHouseSeries.push_back(houses[i]);
            } 
            if (i != 0) { //We can't use if-else as, this will break the floe of execution on first if-block only; as anyways inside every for loop iteration we are going to have first elemement
                lastHouseSeries.push_back(houses[i]);
            }
        }
        return max(maximumRobbery(firstHouseSeries), maximumRobbery(lastHouseSeries));

}
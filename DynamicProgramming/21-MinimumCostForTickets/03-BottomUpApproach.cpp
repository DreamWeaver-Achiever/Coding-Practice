/*
Platform: Code360
Problem Link: https://www.naukri.com/code360/problems/minimum-coins_2180776?leftPanelTab=0&leftPanelTabValue=PROBLEM
Problem statement:
Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.
The passes allow for many days of consecutive travel.
Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,
If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 365
1 <= DAYS[i] <= 365

Time Limit: 1 sec
*/

/*
Complexities ->
Time Complexity -> O(n).
Space Complexity -> O(n).
*/

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int> dynamicArray(n+1, INT_MAX); //We need to calculate minimum that's why need to use INT_MAX;
    dynamicArray[n]=0;

    for(int k=n-1; k>=0; k--) { // Here, dp[n]=0; so, we need to go from n-1 to 0.

    //1 day pass
    int opt1 = cost[0]+dynamicArray[k+1];

    //7 day pass
    int i;
    for(i=k; i<n&&days[i]<days[k]+7; i++);
    int opt2 = cost[1]+ dynamicArray[i];

    //30 day pass
    for(i=k; i<n&&days[i]<days[k]+30; i++);
    int opt3 = cost[2]+dynamicArray[i];

    dynamicArray[k] = min(opt1, min(opt2, opt3));

    }
    return dynamicArray[0];
}
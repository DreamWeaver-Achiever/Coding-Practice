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
Time Complexity -> O(3^n).
Space Complexity -> O(n).
*/
int calculateMinimumCoins(int n, vector<int>& days, vector<int>& cost, int index) {
    //Base case - Already on last day or more than last day
    if(index >= n) {
        return 0;
    } 

    // 1-day pass
    int opt1 = cost[0] + calculateMinimumCoins(n, days, cost, index+1);

    //7-day pass
    int i;
    for(i=0; i<n&&days[i]<days[index]+7; i++); // We have considered this for loop to only increase the index and there won't be any body to it.
    int opt2 = cost[1] + calculateMinimumCoins(n, days, cost, i);

    //30-day pass
    for(int i=index; i<n&&days[i]<days[index]+30; i++);
    int opt3=cost[2]+calculateMinimumCoins(n, days, cost, i);

    return min(opt1, min(opt2, opt3));

}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    calculateMinimumCoins(n, days, cost, 0);
}
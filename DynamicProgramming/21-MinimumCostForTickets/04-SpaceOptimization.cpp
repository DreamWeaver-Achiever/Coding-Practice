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
Space Complexity -> O(1).
*/

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    int ans = 0; //We can't use INT_MAX as we are updateing ans on line 21, if we use INT_MAX then, this will result in -ve range.
    queue<pair<int, int>> monthly;
    queue<pair<int, int>> weekly;

    for(int day:days) {
        //Step-1 -> Remove expired days.
        while(!monthly.empty() && monthly.front().first+30 <= day) {
            monthly.pop();
        }
        while(!weekly.empty() && weekly.front().first+7 <= day) {
            weekly.pop();
        }

        //Step-2 -> Add cost of current day.
        weekly.push(make_pair(day, ans+cost[1]));
        monthly.push(make_pair(day, ans+cost[2]));

        //Step-3 -> Update answer.
        ans = min(ans+cost[0], min(weekly.front().second, monthly.front().second));
    } 
    return ans;
}
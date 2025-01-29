/*
Platform -> Code360
ProblemLink -> https://www.naukri.com/code360/problems/nth-fibonacci-number_74156
The n-th term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -

    F(n) = F(n - 1) + F(n - 2), 
    Where, F(1) = 1, F(2) = 1


Provided 'n' you have to find out the n-th Fibonacci Number. Handle edges cases like when 'n' = 1 or 'n' = 2 by using conditionals like if else and return what's expected.

"Indexing is start from 1"


Example :
Input: 6

Output: 8

Explanation: The number is ‘6’ so we have to find the “6th” Fibonacci number.
So by using the given formula of the Fibonacci series, we get the series:    
[ 1, 1, 2, 3, 5, 8, 13, 21]
So the “6th” element is “8” hence we get the output.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
6


Sample Output 1:
8


Explanation of sample input 1 :
The number is ‘6’ so we have to find the “6th” Fibonacci number.
So by using the given formula of the Fibonacci series, we get the series:    
[ 1, 1, 2, 3, 5, 8, 13, 21]
So the “6th” element is “8” hence we get the output.


Expected time complexity :
The expected time complexity is O(n).


Constraints:
1 <= 'n' <= 10000     
Where ‘n’ represents the number for which we have to find its equivalent Fibonacci number.

Time Limit: 1 second
*/

//Space Optimization In Down-Top Approach (Most Optimized)
// Time Complexity -> O(n)
// Space Complexity -> O(1)
#include<bits/stdc++.h>
using namespace std;

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int nthTerm;
        cin>>nthTerm;
        int previousTerm1 = 1;
        int previousTerm2 = 0;

        //Check for the nthTerm=0; Exceptional case, this will not occur in the given problem considering, in this problem series is supposed to start from '1'.
        // if (nthTerm = 0) {
        //   return previousTerm2;
        // }

        for(int i=2; i<=nthTerm; i++) {
                int currentTerm = previousTerm1 + previousTerm2;
                //Shift the logic forward in the series.
                previousTerm2 = previousTerm1;
                previousTerm1 = currentTerm;

        } 
        cout<<previousTerm1<<endl;
}
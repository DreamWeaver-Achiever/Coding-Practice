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

//Top To Down Approach (Memoization)-> 
// Time Complexity -> O(n)
// Space Complexity -> O(n) + O(n)
#include<bits/stdc++.h>
using namespace std;

int calculateFibonacci(int nthTerm, vector<int>&dynamicArray){
        //Base case
        if(nthTerm<=1) {
                return nthTerm;
        }
        //Step2 - Check if element is != -1
        if(dynamicArray[nthTerm] != -1) {
                return dynamicArray[nthTerm];
        }
        //Step3 - If element is == -1, then f(n) = f(n-1) + f(n-2)
        dynamicArray[nthTerm] = calculateFibonacci(nthTerm-1, dynamicArray) + calculateFibonacci(nthTerm-2, dynamicArray);
        return dynamicArray[nthTerm];

}
int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int nthTerm;
        cin>>nthTerm;

        //Step1 - Declare dynamic array with size n+1 and all elements = -1.
        vector<int>dynamicArray(nthTerm+1);
        for(int i=0; i<=nthTerm; i++) { 
                dynamicArray[i] = -1;    
        }
        cout<<calculateFibonacci(nthTerm, dynamicArray)<<endl;
        return 0;
}
/*
Platform: Code360.
Problem Link: https://www.naukri.com/code360/guided-paths/data-structures-algorithms/content/651072/offering/10442099?leftPanelTabValue=PROBLEM
Problem statement:
You are given two non-negative integers, ‘NUM1’ and ‘NUM2’, in the form of strings. Return the sum of both strings.



Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Example:
Let ‘NUM1’ be: “5”
Let ‘NUM2’ be: “21”
The sum of both numbers will be: “26”.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= |NUM1|, |NUM2| <= 10^5

NUM1 and NUM2 don’t have leading zeroes.
Where |NUM1| and |NUM2| denote the length of the respective strings.

Time limit: 1 sec
Sample Input 1 :
2
5 21
10 9
Sample output 1 :
26
19
Explanation For Sample Output 1 :
For the first test case:
The sum of both numbers will be: “26”.

For the second test case:
The sum of both numbers will be: “19”.
Sample Input 2 :
2
9 9
21 10
Sample output 2 :
18
31
*/

#include <bits/stdc++.h> 

string stringSum(string &num1, string &num2) {

    int length1 = num1.length()-1;
    int length2 = num2.length()-1;
    int count = 0;

    string ans="";

    // loop until which the strings are running equal
    while(length1>=0 && length2>=0){
        int current = (num1[length1]-'0') + (num2[length2]-'0') + count;
        ans += to_string((current%10));
      if(current>=10){
            count = 1;
        }
        else{
            count = 0;
        }
        length1--;
        length2--;
    }

    // loop till which length1 has some characters left
    while(length1>=0){
        int current = (num1[length1]-'0') + count;
        ans += to_string((current%10));
        if(current>=10){
            count = 1;
        }
        else{
            count = 0;
        }
        length1--;
    }

    // loop till which length2 still has some characters left 
    while(length2>=0){
        int current = (num2[length2]-'0') + count;
        ans += to_string((current%10));
        if(current>=10){
            count = 1;
        }
        else{
            count = 0;
        }
        length2--;
    }

    if(count){
        ans+= to_string(count);
    }

    reverse(ans.begin(),ans.end());
    return ans;

}
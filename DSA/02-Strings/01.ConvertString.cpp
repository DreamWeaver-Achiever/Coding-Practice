/*
Platform -> Code360
Problem Link -> https://www.naukri.com/code360/guided-paths/data-structures-algorithms/content/651072/offering/10442100?leftPanelTabValue=PROBLEM
Problem statement:
You are given a string 'STR'. You have to convert the first alphabet of each word in a string to UPPER CASE.

For example:

If the given string 'STR' = ”I am a student of the third year” so you have to transform this string to ”I Am A Student Of The Third Year"
Note:

'STR' will contains only space and alphabets both uppercase and lowercase. The words will be separated by space.
Detailed explanation ( Input/output format, Notes, Images )
*/
#include <bits/stdc++.h> 
string convertString(string str) 
{
	// WRITE YOUR CODE HERE
	int n = str.size();
	for (int i = 0; i < n;  i++) { 
		if(i==0) {
			str[0] = toupper(str[0]); 
		} 
		if(str[i] == ' ' and (i+1 <n)) { 
			str[i+1] = toupper(str[i+1]);
        }
	}
        return str;
}
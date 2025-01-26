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
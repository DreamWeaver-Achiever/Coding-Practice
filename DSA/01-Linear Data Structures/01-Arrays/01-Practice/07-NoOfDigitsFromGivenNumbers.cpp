#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main() {
    cout<<"Program takes the elements of the vector arr and constructs a number by treating them as digits in reverse order."; 
    int no=0;
    vector<int> arr = {3, 4, 5};
    for(int i=0; i<arr.size(); i++) {
        while(i<arr.size()) {
        no = no+arr[i]*pow(10, i);
        i++;
        }
    } 
    cout<<"\nThe number is: "<<no;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;
int main() {
    cout<<"Caluculate Mean/Average of elements in an array."<<endl;
    vector<int> arr = {10, 20, 30, 40, 50};
    int sum = 0;
    for(int i=0; i<arr.size(); i++) {
        sum = sum + arr[i];
    }
    int mean = sum/arr.size();
    cout<<"Mean/Average of elements in an array: "<<mean<<endl;
    return 0;
}
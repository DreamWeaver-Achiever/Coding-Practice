#include<iostream>
#include<vector>

using namespace std;
int main() {
    cout<<"Find out maximum and minimum of an array along with their positions\n";
    vector<int> arr = {1, 3, 5, 2, 4};
    int smallest=99999, largest=-99999, pos1=-1, pos2=-1;
    for(int i=0; i<=arr.size()-1; i++) {
        if(arr[i]<smallest) {
            smallest = arr[i];
            pos1=i;
        }
        if(arr[i]>largest) {
            largest=arr[i];
            pos2=i;
        }
    }
    cout<<"Smallest element of an array is: "<<smallest<<" and its position is: "<<pos1<<endl;
    cout<<"Largest element of an array is: "<<largest<<" and its position is: "<<pos2<<endl;
    return 0;

}
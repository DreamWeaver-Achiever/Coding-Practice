#include <iostream>
#include <vector>

using namespace std;
int main() {
    cout<<"2D Array Basics"<<endl;
    vector<vector<int>> Arraytype2d(3, vector<int>(3));
    // Initialize the Arraytype2d
     Arraytype2d[0][0] = 1;
     Arraytype2d[0][1] = 2;
     Arraytype2d[0][2] = 3;
     Arraytype2d[1][0] = 4;
     Arraytype2d[1][1] = 5;
     Arraytype2d[1][2] = 6;
     Arraytype2d[2][0] = 7;
     Arraytype2d[2][1] = 8;
     Arraytype2d[2][2] = 9;
 
     // Access and print elements
     for (int i = 0; i < Arraytype2d.size(); i++) {
         for (int j = 0; j < Arraytype2d[i].size(); j++) { 
            cout << Arraytype2d[i][j] << " ";
         }
         cout<<endl;
     }
     return 0;
}
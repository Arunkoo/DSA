#include <iostream>
using namespace std;

int main() {

    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    for(int i = 1; i <= rows; ++i) {
        for(int j = 1; j <= i; ++j) {
            cout << j;
        }
        cout << "\n";
    }
    return 0;
}


// rows  = 3 ,
// i =1 , 1<=3, i = 2,   j =1, 1<=2, j=2
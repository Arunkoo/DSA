#include <iostream>
using namespace std;

// row wise sum;;;

void printSum(int arr[3][4]){
    cout << "Printing the sum" << endl;
    for(int j=0 ; j<4; j++){
        int sum = 0;
        for(int i = 0; i<3;i++){
            sum+=arr[i][j];
        }
        cout << sum << " ";
    }
}

int main(){

    int myarr[3][4] = {{1,2,3,4}, {5,3,7,2},{6,2,90,3}};

    printSum(myarr);
    

    return 0;
}
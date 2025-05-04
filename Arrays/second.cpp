#include <iostream>
using namespace std;

// for sum ;

int Sum(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n;i++ ){
        sum += arr[i];
    }

    return sum;
}

int main(){
    int size;
    cout << "Enter the size of array: " << endl;
    cin >> size;

    int num[50];
    cout << "Enter value of array: " << endl;
    // taking input in array...
    for(int i = 0; i<size; i++){
        cin >> num[i];
    }


    // sum of an array
    cout << "Sum of an array: "<<Sum(num, size) << endl;




    return 0;
}
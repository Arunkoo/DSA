#include <iostream>
using namespace std;

void SwapAlternate(int arr[], int n){
    int temp;
    for(int i = 0; i < n ; i+=2){
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);
    SwapAlternate(arr, n);
    cout << "Reversed array: ";
    printArray(arr, n);
    return 0;
}
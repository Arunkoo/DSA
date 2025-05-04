#include <iostream>
using namespace std;

bool Search(int arr[], int n, int key){
    for(int i = 0; i<n ; i++){
        if(arr[i] == key){
            return true;
        }
    }
    return false;
}
int main(){
    int size;
    cout << "Enter a size of an array"<< endl;
    cin >> size;

    int num[50];
    cout << "Enter the values of an array: "<< endl;

    

    for(int i = 0; i<size; i++){
        cin >> num[i];
    }
    int key;
    cout << "Enter the value you want to check from above array: " << endl;
    cin >> key;

    cout << "Present or not?  "<< Search(num, size, key );


    return 0;
}
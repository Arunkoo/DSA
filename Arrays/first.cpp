#include <iostream>
#include <climits>
using namespace std;
// fn for returning max and min... 
int Get_Max(int arr[], int n){
    int max = INT_MIN;

    for(int i = 0; i<n ; i++){
        if(arr[i] > max){
            max = arr[i];

        }
    }
    return max;

}

int Get_Min(int arr[], int n){
    int min = INT_MAX;

    for(int i = 0; i<n ; i++){
        if(arr[i] < min){
            min = arr[i];

        }
    }
    return min;

}
int main(){
    int size;
    cout << "Enter size of array"  << endl;
    cin >> size;
    int num[50];

    cout << " Enter array values" << endl;

    for(int i=0; i<size; i++){
        cin >> num[i];
    }

    cout << "Max value is: " <<Get_Max(num, size) << endl;
    cout << "Min value is: " <<Get_Min(num, size) << endl;

    return 0;
}
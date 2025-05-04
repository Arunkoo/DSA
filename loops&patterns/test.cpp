#include<iostream>
using namespace std;
int main(){
    // sum of 1 to n
    int n;
    cout << "Enter Number to print sum" << endl;
    cin >> n;

    int sum = 0;
    for(int i=1; i<=n; i++){
        sum+=i;

    }
    cout << "Total sum =="<< sum << endl;


    return 0;
}
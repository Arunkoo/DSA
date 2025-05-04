#include<iostream>
using namespace std;
int main(){
    int n ;
    cout << "Enter number to print series upto that"<<endl;
    cin >> n;

    int a = 0;
    int b = 1;
    cout << a << " " << b <<" ";
    for(int i = 1; i<=n; i++){
        int nextNumber = a+b;
        cout << nextNumber << " ";
        a = b;
        b = nextNumber;
    }

    return 0;
}


// fibonnaci series...
// 0 1 1 2 3 5 7 12 ......
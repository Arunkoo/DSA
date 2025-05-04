#include <iostream>
#include <vector>
#include <string>
using namespace std;
string removeOccurrences(string s, string part) {
    // code anywhere
    string result;

    for(char c : s){
        result.push_back(c);

        // condition .... 
        if(result.size() >= part.size() && result.substr(result.size()-part.size()) == part){
            result.erase(result.size() - part.size());
        }
    }

    return result;
}
int main()
{
    string s;
    string part;
    
    cout << "Enter first string" << endl;
    cin >> s;
    cout << "Enter a substring to remove "  << endl;
    cin >> s;
    
    
    
    
    cout << "The final string after removing a substring" << " "<< removeOccurrences(s,part);
	return 0;
}
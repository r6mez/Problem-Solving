#include <iostream>
using namespace std;

int main(){
    char c;
    cin >> c;

    if(c >= 48 && c <= 57) cout << "IS DIGIT";
    else {
        cout << "ALPHA" << endl;
        if(c >= 65 && c <= 90) cout << "IS CAPITAL";
        else cout << "IS SMALL"; 
    }
    return 0;
}
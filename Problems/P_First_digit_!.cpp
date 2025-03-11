#include <iostream>
using namespace std;

int main(){
    int x, digit;
    cin >> x;
    digit = x / 1000;
    if (digit % 2 == 0) cout << "EVEN";
    else cout << "ODD"; 
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    unsigned long long a,b,c,d;
    cin >> a >> b >> c >> d;
    a %= 100;
    b %= 100;
    c %= 100;
    d %= 100;
    string digit = to_string((a*b*c*d) % 100); 
    if (digit.length() == 1){
        digit = "0" + digit;
        cout << digit;
    }
    else cout << digit;
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    float number;
    cin >> number;

    int intpart = number;
    float floatpart = number - intpart;
    
    if(floatpart) cout << "float " << intpart << " " << floatpart;
    else cout << "int " << intpart; 
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    char c;
    cin >> c;
    if(c == 122) cout << 'a';
    else cout << (char(c+1));
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int a, b;
    char s;
    cin >> a >> s >> b;
    if((s == '>' && a > b) || (s == '<' && a < b) || (s == '=' && a == b))
        cout << "Right";
    else
        cout << "Wrong";
    return 0;
}
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    int min = 0;
    if(a<b) {
        if (a<c) min = a;
        else min = c;
    } else {
        if (b<c) min = b;
        else min = c;
    }
    cout << min;
    return 0;
}
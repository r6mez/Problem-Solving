#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int x, y; 
    cin >> x >> y;
    if (y != 0) cout << x % y;
    else cout << -1;
    return 0;
}
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    string x,y;
    cin >> x >> y; 
    if(x<=y)cout << x;
    else cout << y;
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    string x,y;
    cin >> x;
    cin >> y; 
    cout << x.length() << ' ' <<  y.length() << endl;
    string newstr = x + ' ' + y;
    cout << newstr;

    return 0;
}
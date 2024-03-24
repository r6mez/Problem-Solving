#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    string x,y;
    cin >> x >> y;
    cout << x.length() << ' ' << y.length() << endl;
    cout << x+y << endl;
    swap(x[0],y[0]);
    cout << x << " " << y;

    return 0;
}
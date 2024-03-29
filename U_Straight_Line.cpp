#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    double x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << (((y1-y2)*(x2-x3) == (y2-y3)*(x1-x2))? "YES" : "NO"); 
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    double x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    double c1x = (x1+x2)/2, c1y = (y1+y2)/2;
    double c2x = (x3+x4)/2, c2y = (y3+y4)/2;

    double r1 = sqrt(pow(c1y-y1, 2) + pow(c1x-x1,2));
    double r2 = sqrt(pow(c2y-y3, 2) + pow(c2x-x3,2));

    double distance = sqrt(pow(c1y-c2y, 2) + pow(c1x-c2x,2));

    if(r1+r2 >= distance) cout << "YES";
    else cout << "NO";
    return 0;
}

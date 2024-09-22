#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    double x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int n; cin >> n;
    while(n--){
        double x,y; cin >> x >> y;
        double xs[4] = {x1,x2,x3,x4};
        double ys[4] = {y1,y2,y3,y4};
        if((x >= *min_element(xs,xs+4) && x <= *max_element(xs,xs+4) ) && (y >= *min_element(ys,ys+4)  && y <= *max_element(ys,ys+4))) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

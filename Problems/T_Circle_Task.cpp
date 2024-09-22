#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    double x1,y1,r,n;
    cin >> x1 >> y1 >> r >> n;
    while(n--){
        double x2,y2;
        cin >> x2 >> y2;
        double distance = sqrt(pow(y2-y1, 2) + pow(x2-x1,2));
        if(distance > r) cout << "NO\n"; 
        else cout << "YES\n";
    }
    return 0;
}

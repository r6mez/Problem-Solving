#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    double a,b,c; cin >> a >> b >> c;
    if(a<b+c && b<a+c && c<a+b){
        cout<< "Valid\n";
        double s = (a+b+c)/2;
        cout << setprecision(6) << fixed << sqrt(s*(s-a)*(s-b)*(s-c));
     } else {
        cout << "Invalid";
     }
    return 0;
}

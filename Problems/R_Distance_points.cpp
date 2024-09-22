#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    double x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    cout << setprecision(9) << fixed << sqrt(pow(y2-y1, 2) + pow(x2-x1,2));
    return 0;
}

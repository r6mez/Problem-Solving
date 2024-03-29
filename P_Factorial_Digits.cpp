#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    const double E = 2.71828182845904523536;
    const double PI = 3.141592653589793;
    double n; cin >> n;
    if(n == 1) cout << 1 << "\n";
    else cout << "Number of digits of " << n << "! is " << trunc((n*log10(n/E) + log10(2*PI*n)/2)+1) << "\n";
    return 0;
}


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll sum(ll n){
    return n*(n+1)/2;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    ll a, b, x; cin >> a >> b >> x;
    ll ma = max(a,b);
    ll mi = min(a,b);
    cout << ((sum(ma/x) * x) - (sum((mi-1)/x)*x));
    return 0;
}
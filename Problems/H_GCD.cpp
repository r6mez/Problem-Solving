#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

ll GCD(ll a, ll b){
    return (b!=0? GCD(b,a%b) : a);
}

ll LCM(ll a, ll b, ll gcd){
    return (a/gcd) * b;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    ll a,b; cin >> a >> b;
    ll gcd = GCD(a,b);
    ll lcm = LCM(a,b,gcd);
    cout << gcd << " " << lcm;
    return 0;
}

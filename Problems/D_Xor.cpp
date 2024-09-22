#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    ll a,b,q;
    cin >> a >> b >> q;
    int res = q%3;
    if(res==1){
        cout << a;
    } else if (res==2){
        cout<< b;
    } else {
        cout << (a^b);
    }
    return 0;
}


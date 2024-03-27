#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int l,r,m; cin >> l >> r >> m;
    unsigned ll prod = 1;
    for (int i = l; i <= r; i++)
    {
        prod *= i;
        prod %= m;
    }
    cout << prod;
    return 0;
}

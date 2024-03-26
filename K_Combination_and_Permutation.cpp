#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#define ll long long


unsigned ll fac(int n){
    unsigned ll fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

unsigned ll combinations(int n, int r) {
    unsigned ll res = 1;
    for (int i = 1; i <= r; ++i) {
        res *= n - r + i;
        res /= i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n,r; cin >> n >> r;
    unsigned ll comp = combinations(n,r);
    unsigned ll perm = comp * fac(r);
    cout << comp << " " << perm;
    return 0;
}

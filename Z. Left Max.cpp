#include <bits/stdc++.h>
using namespace std;
#define ll long long

void printMaxFrom1toI(int n, int i = 0, ll maxx = LLONG_MIN){
    if(i == n) return;
    ll num; cin >> num;
    cout << (maxx = max(maxx, num)) << " ";
    printMaxFrom1toI(n,i+1, maxx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    cout << INT_MAX;
    printMaxFrom1toI(n);
    return 0;
}

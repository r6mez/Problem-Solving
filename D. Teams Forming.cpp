#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a,a+n);
    int steps = 0;
    for (int i = 0; i < n; i += 2) {
        steps += (a[i+1] - a[i]);
    }
    cout << steps;
    return 0;
}

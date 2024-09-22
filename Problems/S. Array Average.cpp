#include <bits/stdc++.h>
using namespace std;
#define ll long long


double average(ll a[], double n, int i = 0, ll sum = 0){
    sum += a[i];
    if(i == n-1) {
        return sum/n;
    } else {
        return average(a,n,i+1,sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << setprecision(6) << fixed << average(a, n);
    return 0;
}

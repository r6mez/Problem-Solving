#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vll a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if(n!=1) {
            sort(a.begin(), a.end());
            int medianIndex = ceil((n-1)/2);
            ll oldMedian = a[medianIndex];
            int nB = 0;
            while(a[medianIndex++] == oldMedian){
                nB++;
            }
            cout << nB << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
    return 0;
}
// 1 1 2 2 3 4
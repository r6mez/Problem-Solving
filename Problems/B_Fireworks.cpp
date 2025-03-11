#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ull a, b, m;
        cin >> a >> b >> m;
        ull aTogther = 0, bTogther = 0;
        // calculate number of a's shown together
        aTogther = (m+a)/a;
        // calculate number of b's shown together
        bTogther = (b+m)/b;
        cout << (aTogther + bTogther) << "\n";
    }
    return 0;
}

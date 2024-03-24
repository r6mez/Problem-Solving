#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll combinations(int n, int r) {
    ll res = 1;
    for (int i = 1; i <= r; ++i) {
        res *= n - r + i;
        res /= i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r;
    cin >> n >> r;
    if (n < r) {
        cout << 0 << "\n";
    } else {
        cout << combinations(n, r) << "\n";
    }

    return 0;
}

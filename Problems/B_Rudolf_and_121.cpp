#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool isPossible = true;
        for (int i = n - 2; i >= 1; --i) {
            long long ops = min({a[i - 1], a[i] / 2, a[i + 1]});
            a[i - 1] -= ops;
            a[i] -= 2 * ops;
            a[i + 1] -= ops;
        }

        for (int i = 0; i < n; ++i) {
            if (a[i] != 0) {
                isPossible = false;
                break;
            }
        }

        cout << (isPossible ? "YES\n" : "NO\n");
    }
    return 0;
}

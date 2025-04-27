#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void Ramez() {
    int l = 1, r = 1e9 + 5;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        cout << mid << "\n";
        cout.flush();
        char result;
        cin >> result;

        if (result == '=') {
            cout << "! " << mid << "\n";
            cout.flush();
            return;
        }
        else if (result == '<') {
            r = mid - 1;
        }
        else if (result == '>') {
            l = mid + 1;
        }
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}
/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. USB vs. PS/2
// URL: https://codeforces.com/contest/762/problem/B
// Time: 5/15/2025, 3:51:29 PM
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
    int a, b, c; cin >> a >> b >> c;
    int n; cin >> n;
    vi pa, pb;
    for (int i = 0; i < n; i++) {
        int price; string type;
        cin >> price >> type;

        if (type == "USB") pa.push_back(price);
        if (type == "PS/2") pb.push_back(price);
    }

    sort(all(pa), greater<>());
    sort(all(pb), greater<>());

    int ag = 0, bg = 0, cg = 0;
    int cost = 0;

    while (!pa.empty() && ag < a) {
        ag++;
        cost += pa.back();
        pa.pop_back();
    }

    while (!pb.empty() && bg < b) {
        bg++;
        cost += pb.back();
        pb.pop_back();
    }

    while (cg < c) {
        if (!pa.empty() && !pb.empty()) {
            if (pa.back() < pb.back()) {
                cg++;
                cost += pa.back();
                pa.pop_back();
            }
            else {
                cg++;
                cost += pb.back();
                pb.pop_back();
            }
            continue;
        }

        if (!pa.empty() && pb.empty()) {
            cg++;
            cost += pa.back();
            pa.pop_back();
            continue;
        }

        if (pa.empty() && !pb.empty()) {
            cg++;
            cost += pb.back();
            pb.pop_back();
            continue;
        }

        break;
    }

    cout << ag + bg + cg << " " << cost;
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
/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// L. Reqtangle medium
// URL: https://codeforces.com/group/E23MsQv91X/contest/323789/problem/L
// Time: 1/27/2025, 10:08:54 AM
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi   vector<int>
#define pii  pair<int, int>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int  dx[] = { -1,   1,   0,   0 }; int  dy[] = { 0,   0,  -1,   1 }; char dir[] = { 'U', 'D', 'L', 'R' };
int MOD = 1000000007;

pii midPoint(pii p1, pii p2) {
    return { p1.first + p2.first, p1.second + p2.second };
}


void Ramez() {
    int n; cin >> n;
    vector<pii> points(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        points[i] = {x, y};
    }

    map<pii, int> midpointMap;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pii midpoint = midPoint(points[i], points[j]);
            midpointMap[midpoint]++;
        }
    }
    
    int counter = 0;
    for (auto &[midpoint, count] : midpointMap) {
        if (count > 1) {
            counter += (count * (count - 1)) / 2; 
        }
    }

    cout << counter << "\n";
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


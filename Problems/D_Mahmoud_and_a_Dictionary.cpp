/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// D. Mahmoud and a Dictionary
// URL: https://codeforces.com/contest/766/problem/D
// Time: 7/28/2025, 9:22:57 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

int n, m, q;
int parent[200200];
int get(int v) {
    if (parent[v] == v) return v;
    return parent[v] = get(parent[v]);
}

bool isSyn(int x, int y) {
    return get(x) == get(y);
}

bool isAnt(int x, int y) {
    return get(x) == get(y + n);
}

void mergeSyns(int x, int y){
    parent[get(x)] = get(y);
}

void mergeAnts(int x, int y){
    parent[get(x + n)] = get(y + n);
}

void Ramez() {
    cin >> n >> m >> q;
    vector<string> s(n);
    map<string, int> idx;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        idx[s[i]] = i;
        parent[i] = i;
        parent[i + n] = i + n;
    }


    for (int i = 0; i < m; ++i) {
        int t; string u, v; cin >> t >> u >> v;
        int x = idx[u], y = idx[v];

        if (t == 1) {
            if (isAnt(x, y)) {
                cout << "NO" << "\n";
            }
            else {
                if (!isSyn(x, y)) {
                    mergeSyns(x, y);
                }
                if (!isSyn(x + n, y + n)) {
                    mergeAnts(x, y);
                }
                cout << "YES" << "\n";
            }
        }
        else {
            if (isSyn(x, y)) {
                cout << "NO" << "\n";
            }
            else {
                if (!isSyn(x, y)) {
                    parent[get(x)] = get(y + n);
                }
                if (!isSyn(x + n, y + n)) {
                    parent[get(x + n)] = get(y);
                }
                cout << "YES" << "\n";
            }
        }
    }
    
    for (int i = 0; i < q; ++i) {
        string u, v; cin >> u >> v;
        int x = idx[u], y = idx[v];
        if (isSyn(x, y)) cout << 1 << "\n";
        else if (isAnt(x, y)) cout << 2 << "\n";
        else cout << 3 << "\n";
    }
}

/*
NOTES:
2 hi fuck
2 hello fuck
hi == hello
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}
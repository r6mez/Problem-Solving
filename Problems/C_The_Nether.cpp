/*
    One day, I'm gonna grow wings
*/
// C. The Nether
// URL: https://codeforces.com/contest/2133/problem/C
// Time: 8/25/2025, 9:53:51 AM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

int ask(int x, int k, vi a) {
    cout << "? " << x << " " << k << " " << a << endl;
    cout.flush();
    int answer; cin >> answer; return answer;
}

void answer(int k, vi a) {
    cout << "! " << k << " " << a << endl;
    cout.flush();
}

void solve() {
    int n; cin >> n;
    vi depth(n + 1);
    vi nodes(n); iota(all(nodes), 1LL);
    for (int i = 1; i <= n; i++){
        depth[i] = ask(i, n, nodes);
    }
    
    int maxDepth = 0, startingNode = 0;
    for (int i = 1; i <= n; i++){
        if(depth[i] > maxDepth){
            maxDepth = depth[i];
            startingNode = i;
        }
    }
    
    vi path; path.push_back(startingNode);

    for (int d = maxDepth - 1; d >= 1; d--){
        for(int v : nodes){
            if(depth[v] == d){
                int answer = ask(path.back(), 2, {path.back(), v});
                if(answer == 2){
                    path.push_back(v);
                    break;
                }
            }
        }
    }

    answer(path.size(), path);
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
// D. Folka and Movies
// URL: https://codeforces.com/group/Rilx5irOux/contest/638270/problem/D
// Time: 5/13/2026, 1:13:27 PM
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

struct movie {
    string name = "";
    int id = 0;
    string original_id = "";
};

void solve() {
    int n ; cin >> n ;
    vector<string> movies(n);
    for(int i = 0; i<n;++i){
        cin >> movies[i] ;
    }

    vector<movie> a(n);
    for(int i = 0; i < n;++i){
        string s = movies[i];
        for(int j = 0; j < s.size(); ++j){
            if(s[j] == '-'){
                a[i].name = s.substr(j+1);
                a[i].id = stoll(s.substr(0,j));
                a[i].original_id = s.substr(0, j);
            }
        }
    }

    sort(all(a), [&](const auto &x, const auto &y){
        if(x.name != y.name) return x.name < y.name;
        return x.id < y.id;
    }); 

    for(auto x : a){
        cout << x.original_id << "-" << x.name << endl;
    }
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
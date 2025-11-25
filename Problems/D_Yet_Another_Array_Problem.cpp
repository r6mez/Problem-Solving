/*
    One day, I'm gonna grow wings
*/
// D. Yet Another Array Problem
// URL: https://codeforces.com/contest/2167/problem/D
// Time: 10/29/2025, 8:11:03 PM
#include <bits/stdc++.h>
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


int MAXN = 100;

vector<bool> isPrime(MAXN, true);

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    set<int> s(all(a));

    vi divCount(1e5, 0);

    for (int o : s){
        for (int i = 1; i < MAXN && i * i <= o; i++) {
            if (o % i == 0) {
                divCount[i]++;
                if (i * i != o && o / i < MAXN) divCount[o / i]++;
            }
        }
    }
    
    for (int x = 2; x < isPrime.size(); x++){
        if(isPrime[x] == true && divCount[x] != s.size()) finish(x);
    }
}

/*

*/

signed main() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < MAXN; j += i){
            isPrime[j] = false;
        }
    }

    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
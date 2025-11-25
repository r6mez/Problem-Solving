/*
    One day, I'm gonna grow wings
*/
// A. Transformation: from A to B
// URL: https://codeforces.com/contest/727/problem/A
// Time: 10/24/2025, 4:29:25 PM
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

int a, b;
vi answer;

bool go(int x){
    if(x > b)
        return false;
    
    if(x == b){
        answer.push_back(x);
        return true;
    }

    if(go(2 * x) || go(10 * x + 1)){
        answer.push_back(x);
        return true;
    }
    
    return false;
}

void solve() {
    cin >> a >> b;
    if(go(a)){
        reverse(all(answer));

        cout << "YES\n";
        cout << answer.size() << "\n";
        cout << answer << "\n";
    } else {
        cout << "NO\n";
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
/*
    One day, I'm gonna grow wings
*/
// D. MAD Interactive Problem
// URL: https://codeforces.com/contest/2160/problem/D
// Time: 10/18/2025, 7:59:18 PM
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

int ask(vi s){
    cout << "? " << s.size() << " " << s;
    cout.flush();
    int answer;
    cin >> answer;
    return answer;
}

void answer(vi a){
    cout << "! " << " " << a;
    cout.flush();
}

void solve() {
    int n; cin >> n;
    vi a(2 * n);
    
    vi s;
    for (int i = 0; i < a.size(); i++){
        s.push_back(i + 1);
        int answer = ask(s);
        if(answer != 0){
            a[i] = answer;
            s.pop_back();
        }
    }

    s.clear();
    for (int i = 0; i < a.size(); i++){
        if(a[i] != 0) s.push_back(i + 1);
    }
    
    for (int i = 0; i < a.size(); i++){
        if(a[i] == 0){
            s.push_back(i + 1);
            int answer = ask(s);
            a[i] = answer;
            s.pop_back();
        }
    }
    
    answer(a);
}

/*
1 1 2 2
(1 1) 2 2 -> 1 [1 1]
1 1 (2 2) -> 2 [1 1 2 2]

1 2 2 1

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
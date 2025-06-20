/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Sports Betting
// URL: https://codeforces.com/contest/2098/problem/C
// Time: 6/2/2025, 12:44:05 PM
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
    int n; cin >> n;
    vi a(n); cin >> a;
    map<int, int> m;

    for (int i = 0; i < n; i++){
        m[a[i]]++;
        if(m[a[i]] == 4){
            cout << "Yes\n";
            return;
        }
    }

    int opened = 0, last = 0;
    for(auto [x, f] : m){
        if(f >= 2 && !opened){
            opened = x;
            last = opened;
            continue;
        } 

        if(opened && f == 0){
            opened = 0;
            continue;
        }

        if(opened && f == 1){
            if(x - last > 1){
                opened = 0;
                continue;
            }
            last = x;
            continue;
        }

        if(opened && f >= 2){
            if(x - last > 1){
                opened = x;
                last = x;
                continue;
            }
            cout << "Yes\n";
            return;
        }
    }
    
    cout << "No\n";
}

/*
NOTES:
2 4 3 2 4
2 -> (3, 4)
2 -> (3, 4)
3 -> (4, 5)
4 -> (5, 6)
4 -> (5, 6)

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}
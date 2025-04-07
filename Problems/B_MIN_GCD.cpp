/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. MIN = GCD
// URL: https://codeforces.com/contest/2084/problem/B
// Time: 4/5/2025, 4:51:19 PM
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
    int mn = *min_element(all(a));
    // cout << mn << "\n";
    int cntMin = 0;
    for (int i = 0; i < n; i++){
        cntMin += (a[i] == mn);
    }
    
    if(cntMin >= 2){
        cout << "Yes\n"; 
        return;
    }

    vi r;
    for (int i = 0; i < n; i++){
        if(a[i] != mn && a[i] % mn == 0) r.push_back(a[i]);
    }

    if(r.empty()){
        cout << "No\n"; 
        return;
    }

    // cout << r << "\n";

    int g = r[0];
    for (int i = 1; i < r.size(); i++){
        g = gcd(g, r[i]);
    }
    
    if(g == mn) cout << "Yes\n";
    else cout << "No\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}
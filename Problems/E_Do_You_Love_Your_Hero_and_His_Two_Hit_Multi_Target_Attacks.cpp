/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Do You Love Your Hero and His Two-Hit Multi-Target Attacks?
// URL: https://codeforces.com/problemset/problem/2072/E
// Time: 4/30/2025, 2:24:34 PM
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

int sum(int n){
    return (n*(n + 1))/2;
}


void Ramez() {
    int k; cin >> k;
    vector<pii> p;

    int dups;
    int rem = k;
    int x = 1, y = 0;

    while(rem > 0){
        int l = 0, r = k + 5;
        while(l + 1 < r){
            int mid = (l + r)/2;
            if(rem - sum(mid - 1) >= 0) l = mid;
            else r = mid;
        }

        dups = l;
        for (int i = 0; i < dups; i++){
            p.push_back({x, y + (i + 1)});
        }
        
        x++;
        y += dups;
        rem -= sum(dups - 1);
    }

    cout << p.size() << "\n";
    for (int i = 0; i < p.size(); i++){
        auto [x, y] = p[i];
        cout << x << " " << y << "\n";
    }

    cout << "\n";
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
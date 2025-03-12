/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Binary Search
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/264941/problem/A
// Time: 3/12/2025, 10:12:38 PM
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
    int n, q; cin >> n >> q;
    vector<pii> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    

    while(q--){
        string s; cin >> s;
        pii x; cin >> x.first >> x.second;

        if(s == "upper"){
            int l = -1, r = n;
            
            while(l + 1 < r){
                int mid = (l + r)/2;
                if(a[mid] > x) r = mid;
                else l = mid;
            }

            if(r >= n) cout << "-1\n";
            else cout << r << "\n";
        } else if (s == "lower"){
            int l = -1, r = n;

            while(l + 1 < r){
                int mid = (l + r)/2;
                if(a[mid] < x) l = mid;
                else r = mid;
            }

            cout << l << "\n";
        } else {
            int l = -1, r = n;
            
            while(l + 1 < r){
                int mid = (l + r)/2;
                if(a[mid] >= x) r = mid;
                else l = mid;
            }

            if(r < n && a[r] == x) cout << "found\n";
            else cout << "not found\n";
        }
    }
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
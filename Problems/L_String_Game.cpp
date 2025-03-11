/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// L. String Game
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/L
// Time: 3/11/2025, 2:09:08 PM
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

bool can(string t, string p, vi a){
    // We need to check if we removed first mid indices 
    // in a from t is p will remain a subsequance of t or not

    sort(all(a));
    string newt = "";
    for (int i = 0; i < t.size(); i++){
        if(!binary_search(all(a), i + 1)){
            newt.push_back(t[i]);
        }
    }
    

    int x = 0, y = 0;
    while(x < newt.size() && y < p.size()){
        if(newt[x] == p[y]){
            x++;
            y++;
        } else {
            x++;
        }
    }

    return y == p.size();
}

void Ramez() {
    string t, p; cin >> t >> p;
    int n = t.size(), m = p.size();
    vi a(n); cin >> a;

    // we're searching for the maximum index 
    // that gives a vaild solution
    int l = 0, r = n;
    while(l + 1 < r) {
       int mid = (l + r)/2;
        if(can(t, p, vi(a.begin(), a.begin() + mid))){
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << "\n";
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
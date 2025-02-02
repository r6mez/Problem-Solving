/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// F. Smaller
// URL: https://codeforces.com/problemset/problem/1742/F
// Time: 1/28/2025, 6:28:46 PM
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi   vector<int>
#define pii  pair<int, int>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int  dx[] = { -1,   1,   0,   0 }; int  dy[] = { 0,   0,  -1,   1 }; char dir[] = { 'U', 'D', 'L', 'R' };
int MOD = 1000000007;


void Ramez() {
    int n; cin >> n;
    vi s(26), t(26);

    s[0]++; t[0]++;

    bool tHasOtherLettersThanA = false, sHasOtherLettersThanA = false;
    for (int i = 0; i < n; i++){
        int ops, k; string x; cin >> ops >> k >> x;
        if(ops == 1){
            for (int j = 0; j < x.size(); j++){
                s[x[j] - 'a'] += k;
                if(x[j] != 'a') sHasOtherLettersThanA = true;
            }
        } else {
            for (int j = 0; j < x.size(); j++){
                t[x[j] - 'a'] += k;
                if(x[j] != 'a') tHasOtherLettersThanA = true;
            }
        }
        
        // cout << s << "\n" << t << "\n";

        if(tHasOtherLettersThanA){
            cout << "YES\n";
        } else {
            if(t[0] > s[0] && !sHasOtherLettersThanA) cout << "YES\n";
            else cout << "NO\n";
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
    cin >> t;
    while (t--) Ramez();
    return 0;
}


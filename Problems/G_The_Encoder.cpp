/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// G. The Encoder
// URL: https://codeforces.com/group/Rilx5irOux/contest/605910/problem/G
// Time: 5/9/2025, 5:13:11 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("encoder.in", "r", stdin); }
const int MOD = 1000000007;

void Ramez() {
    string s; cin >> s;
    string keys; cin >> keys;

    sort(all(keys));

    string original = "";

    for (int i = 0; i < s.size(); i++){
        if(binary_search(all(keys), s[i])){
            if((i == s.size() - 1) || (s[i + 1] != 'k')){
                cout << "IMPOSSIBLE\n";
                return;
            } else {
                original += s[i];
                i++;
            }
        } else {
            original += s[i];
        }
    }
    
    cout << original << "\n";
}

/*
NOTES:

*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}
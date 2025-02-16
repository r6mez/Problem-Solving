/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// B. Letter
// URL: https://codeforces.com/contest/43/problem/B
// Time: 2/13/2025, 12:48:15 AM
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
    string head, text;
    getline(cin, head);
    getline(cin, text);
    vi freq(55, 0);
    for (char c : head) {
        if (c != ' ') {
            if (islower(c))
                freq[c - 'a' + 26]++;
            else
                freq[c - 'A']++;
        }
    }
    for (char c : text) {
        if (c != ' ') {
            if (islower(c)) {
                if (!freq[c - 'a' + 26])
                    return void(cout << "NO\n");
                freq[c - 'a' + 26]--;
            } else {
                if (!freq[c - 'A'])
                    return void(cout << "NO\n");
                freq[c - 'A']--;
            }
        }
    }
    cout << "YES\n";
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


// C. Sorting Game
// URL: https://codeforces.com/contest/2191/problem/C
// Time: 1/18/2026, 8:31:20 PM
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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int z = 0, o = 0;
    for (char c : s) {
        if (c == '0') z++;
        else o++;
    }
    int cnt1 = 0, cnt2 = 0;

    vi positions;

    if(!o || !z) finish("Bob");
    
    for (int i = 0; i < z; i++) {
        if (s[i] == '1') {
            cnt2++;
            positions.push_back(i + 1);
        }
    }

    for (int i = n - o; i < n; i++) {
        if (s[i] == '0') {
            cnt1++;
            positions.push_back(i + 1);
        }
    }

    if(!cnt1 && !cnt2) finish("Bob");
    
    if (cnt1 == cnt2) {
        cout << "Alice\n";
        cout << positions.size() << "\n";
        cout << positions << "\n";
    } else {
        cout << "Bob\n";
    }
}

/*
you can take a sequence of 11110000 and make it 00001111
if no sequence exist you lose 
print who wins 
and if alice wins 
print it's first move

011
Bob
101
alice 
110
alice

1010101
alice 
[1, 3, 4, 6]

if we have z zeros and o ones 
if number of zeros in the last o positions is equal to the nummber of ones in the first z position 
then alice wins
other wise bob wins 
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
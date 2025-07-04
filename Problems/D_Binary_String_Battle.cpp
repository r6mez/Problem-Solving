/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Binary String Battle
// URL: https://codeforces.com/contest/2123/problem/D
// Time: 7/1/2025, 6:20:25 PM
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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int zeros = 0, ones = 0;
    for (int i = 0; i < n; i++){
        if(s[i] == '1') ones++;
        else zeros++;
    }
    
    if(ones <= k) {
        cout << "Alice\n";
        return;
    }

    if(k + (k - 1) >= n){
        cout << "Alice\n";
        return;
    }

    cout << "Bob\n";
}

/*
NOTES:
6 4
111111
n/2 > 

7 4
1011011
0001000
0001111
0000000

if there's ones in common in [0, k] and [n - k, n]

if alice turned off k element and the remaining is < k
and bob can't turn on more than k elements
then alice wins
otherwise bob loses


1011111
0011000
0011111
0001000 ailce wins

1111111
00
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}
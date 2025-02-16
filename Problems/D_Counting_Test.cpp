/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// D. Counting Test
// URL: https://codeforces.com/problemset/gymProblem/101532/D
// Time: 2/12/2025, 1:02:11 PM
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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<vi> freq(26, vi(n, 0));

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a'][i]++;
    }

    for (int i = 0; i < 26; i++){
        partial_sum(all(freq[i]), freq[i].begin());
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        char c; cin >> c;
        int ci = c - 'a';

        int startSeg = l % n, endSeg = r % n;
        int segmentsBetween = ((r - l + 1) - (n - startSeg) - endSeg) / n;

        int answer = 0;

        if((l / n) * n == (r / n) * n){ // same string;
            answer += freq[ci][endSeg] - (startSeg? freq[ci][startSeg - 1] : 0);
        } else { // Differnet Strings
            answer += freq[ci][n - 1] - (startSeg? freq[ci][startSeg - 1] : 0);
            answer += freq[ci][endSeg];
            answer += freq[ci][n - 1] * segmentsBetween;
        }

        cout << answer << "\n";
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


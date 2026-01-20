// G. Mixing MEXes
// URL: https://codeforces.com/contest/2185/problem/G
// Time: 1/19/2026, 2:28:45 PM
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

    vi lengths(n);
    vector<vi> arrays(n);
    map<int, int> count;
    for (int i = 0; i < n; i++) {
        int length;
        cin >> length;
        lengths[i] = length;
        arrays[i] = vi(lengths[i]);
        for (auto& x : arrays[i]) {
            cin >> x;
            count[x]++;
        }
        sort(arrays[i].begin(), arrays[i].end());
    }

    int mex_sum = 0;
    vi mexes(n);
    vi second_mexes(n);

    // Calculate mex and second mex for each array
    for (int i = 0; i < n; i++) {
        int current_mex = 0;
        for (int j = 0; j < lengths[i]; j++) {
            if (arrays[i][j] > current_mex) break;
            if (arrays[i][j] == current_mex) current_mex++;
        }
        int second_mex = current_mex + 1;
        for (int j = 0; j < lengths[i]; j++) {
            if (arrays[i][j] > second_mex) break;
            if (arrays[i][j] == second_mex) second_mex++;
        }
        mexes[i] = current_mex;
        second_mexes[i] = second_mex;
        mex_sum += current_mex;
    }

    int total = 0;
    // Calculate removals
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < lengths[i]; j++) {
            int org = total;
            bool is_alone = (j == 0 || arrays[i][j - 1] != arrays[i][j]) && (j == lengths[i] - 1 || arrays[i][j + 1] != arrays[i][j]);
            if (is_alone && arrays[i][j] < mexes[i]) total += ((mex_sum - mexes[i] + arrays[i][j])) * (n - 1);
            else total += (mex_sum) * (n - 1);
        }
    }

    // Calculate additions
    for (int i = 0; i < n; i++) {
        total += (count[mexes[i]]) * (second_mexes[i] - mexes[i]);
    }

    cout << total << "\n";
}

/*
n array
sum of all mexes of the arrays for all possible moves
a move: choose an array i and element j and move it to array k (i != k)

number of all elements <= 1e5

for each element in array, you need to try to move it to every other array
if we moved x to array with mex y
    if (x == y) mex changes (next missing number)
    other wise mex stays the same
if the original array has another x or mex < x, mex stays the same


*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
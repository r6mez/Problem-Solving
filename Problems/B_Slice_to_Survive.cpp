/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Slice to Survive
// URL: https://codeforces.com/contest/2109/problem/B
// Time: 5/17/2025, 5:41:18 PM
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

int count(int x) {
    int c = 0;

    while (x > 1) {
        x -= (x / 2);
        c++;
    }
    return c;
}

void Ramez() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    int right = m - b + 1, left = b, top = a, bottom = n - a + 1;
    
    int mnX = min(right, left);
    int mnY = min(top, bottom);

    int answer = min(count(mnX) + count(n), count(mnY) + count(m)) + 1;
    cout << answer << "\n";
}  

/*
NOTES:
if height or length still has more than 3 cells
then it will move to the middle to increase number of cuts

first cut is important, it affect the answer
then we have a pattern

7 -> 4
4 -> 2
2 -> 1
1

2 7
7 -> (7 / 2) = 3 cuts
2 -> (2 / 2) = 1 cut

3 3 2 2
we will cut the right
n = 3, m = 2
remain in the middle and cut until 1 1 (4 cuts)

2 2 1 1
cut right
n = 2 m = 1

8 9 4 6 (6 != 8)
1 2 3 4 5 6 7 8 9
cut top = 5
n = 8, m = 4
n takes 3
m takes 3

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}
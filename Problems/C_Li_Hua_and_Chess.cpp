/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Li Hua and Chess
// URL: https://codeforces.com/problemset/problem/1797/C
// Time: 4/25/2025, 7:02:21 PM
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

int ask(int x, int y){
    cout << "? " << x << " " << y << "\n";
    cout.flush();
    int answer; cin >> answer;
    return answer;
}

void answer(int x, int y){
    cout << "! " << x << " " << y << "\n";
    cout.flush();
}

void Ramez() {
    int n, m; cin >> n >> m;
    int k = ask(1, 1);
    int p = ask(1, min(k + 1, m)), q = ask(min(k + 1, n) , 1);

    if(p < k) answer(p + 1, k + 1);
    else if (q < k) answer(k + 1, q + 1);
    else answer(k + 1, k + 1);
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
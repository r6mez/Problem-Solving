/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// B. Omar thinks he is him
// URL: https://codeforces.com/gym/591877/problem/B
// Time: 2/27/2025, 11:08:29 PM
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
    int n; cin >> n;
    
    vector<pii> orders(n);
    for (int i = 0; i < n; i++) cin >> orders[i].first >> orders[i].second;

    sort(all(orders));

    int currTime = orders[0].first, waitingTime = 0;
    for (int i = 0; i < n; i++){
        waitingTime += max(currTime - orders[i].first, 0LL);
        currTime += orders[i].second;
    }
    
    cout << waitingTime << "\n";
}

/*
NOTES:ٍ

*/

int32_t main() {ٍ
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}


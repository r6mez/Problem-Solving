/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// E1. Permutation Minimization by Deque
// URL: https://codeforces.com/contest/1579/problem/E1
// Time: 2/26/2025, 1:24:38 PM
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
    vi p(n); cin >> p;

    deque<int> dq;

    for (int i = 0; i < n; i++){
        if(dq.empty()) {
            dq.push_back(p[i]);
        } else {
            if(p[i] < dq.front()){
                dq.push_front(p[i]);
            } else {
                dq.push_back(p[i]);
            }
        }
    }

    for(int x : dq){
        cout << x << " ";
    }
    cout << "\n";
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


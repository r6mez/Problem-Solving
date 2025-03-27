/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// A. Las cartas de Dr. Lira
// URL: https://omegaup.com/arena/gsoc2025/practice/#problems/CartasDrLira
// Time: 3/3/2025, 10:15:42 PM
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
    string s; cin >> s;
    int evenBlacks = 0, oddBlacks = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && s[i] == 'B')  evenBlacks++;
        if (i % 2 == 1 && s[i] == 'B')  oddBlacks++;
    }

    int oddIndecies = n/2;
    int evenIndecies = n - oddIndecies;
    if(evenBlacks > oddBlacks){
        cout << evenIndecies - evenBlacks + oddBlacks << endl;
    } else {
        cout << oddIndecies - oddBlacks + evenBlacks << endl;
    }
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


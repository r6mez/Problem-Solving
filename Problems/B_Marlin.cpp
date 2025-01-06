/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll   long long
#define vi   vector<int>
#define vll  vector<ll>
#define pll  pair<ll, ll>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

void Ramez() {
    int n, k; cin >> n >> k;

    cout << "YES\n";
    
    vector<string> ss(4, string(n, '.'));

    if(k <= n - 2) {
        if(k == 1) {
            ss[1][n / 2] = '#';
        }
        else {
            if(k % 2) ss[1][n / 2] = '#';
            for(int i = 0; i < k/2; i++) ss[1][i + 1] = '#';
            for(int i = 0; i < k/2; i++) ss[1][n - 2 - i] = '#';
        }
    }
    else {
        for(int i = 0; i < n - 2; i++) ss[1][i + 1] = '#';
        if(k == n - 1) ss[2][n / 2] = '#';
        else {
            ss[2][1] = '#';
            ss[2][n - 2] = '#';
            for(int i = 0; i < k-n; i++) ss[2][2 + i] = '#';
        }
    }
    
    for (int i = 0; i < 4; i++) {
        cout << ss[i] << "\n";
    }

}

/*
NOTES:
shortest path = n-1 + 3
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}


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
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){ for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v){ for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

void Ramez() {
    int n; cin >> n; 
    vi a(n); cin >> a;

    for (int i = 0; i < n - 1; i++){
        int x = min(a[i], a[i+1]);
        a[i] -= x;
        a[i+1] -= x;
        if(a[i] > a[i+1]) {
            cout << "NO\n";
            return;
        }    
    }
    
    cout << "YES\n";
}

/*
NOTES:
4 3 2 1
1 0 2 1

4 5 4 5 4 5 4 5
0 1 4 5 4 5 4 5
0 0 3 5 4 5 4 5
0 0 0 2 4 5 4 5
0 0 0 0 2 5 4 5
0 0 0 0 0 3 4 5

9 9 8 2 4 4 3 5 3
0 0 8 2 4 4 3 5 3
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}


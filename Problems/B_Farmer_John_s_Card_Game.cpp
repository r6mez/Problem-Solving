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
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m));
    for(vi &i : a) cin >> i, sort(all(i));
    
    vector<vi> copyA(a); sort(all(copyA));

    for (int j = 0; j < m; j++){
        for (int i = 0; i < n-1; i++){
            if(copyA[i+1][j] - copyA[i][j] != 1) {
                cout << -1 << "\n";
                return;
            }            
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(a[j][0] == i) cout << j+1 << " ";
        } 
    }
    
    cout << "\n";
}

/*
NOTES:

*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}


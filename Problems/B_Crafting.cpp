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
    vi a(n), b(n); cin >> a >> b;

    int l = 0, pos = 0, neg = INT_MAX;

    for (int i = 0; i < n; i++){
        if(a[i] < b[i]){
            l++;
            pos = (b[i] - a[i]);
        } else {
            neg = min(neg, a[i] - b[i]);
        }
    }

    if(l > 1){
        cout << "NO\n"; 
        return;
    }

    if(pos <= neg){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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


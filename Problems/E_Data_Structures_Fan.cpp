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
    string s; cin >> s;

    int xor0 = 0, xor1 = 0;
    for (int i = 0; i < n; i++){
        if(s[i] == '0') xor0 ^= a[i];
        else xor1 ^= a[i];
    }
    
    vi prefixXOR(n+1);
    prefixXOR[0] = a[0];
    for (int i = 1; i < n; i++){
        prefixXOR[i] = a[i] ^ prefixXOR[i - 1];
    }
    

    int q; cin >> q;
    while(q--){
        int ops; cin >> ops;
        if(ops == 1){
            int l, r; cin >> l >> r;
            l--; r--;
  
            xor0 ^= (prefixXOR[r] ^ (l == 0? 0 : prefixXOR[l - 1]));
            xor1 ^= (prefixXOR[r] ^ (l == 0? 0 : prefixXOR[l - 1]));
        } else {
            int g; cin >> g;
            if (g == 0) cout << xor0 << " ";
            else cout << xor1 << " ";
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
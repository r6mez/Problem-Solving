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
    vi halal(n);
    for (int i = 0; i < n; i++){
        halal[i] = (a[i] == i+1);
    }

    int segements = 0;
    for (int i = 1; i < n; i++){
        if(halal[i] == 0 && halal[i-1] == 1) segements++;
    }

    if(halal[n-1] == 1) segements++;
    
    
    if(segements == 1 && halal[0] == 1 && halal[n-1] == 1){
        cout << 0 << "\n";
    } else if(segements == 0){
        cout << 1 << "\n";
    } else if(segements == 1 && (halal[0] || halal[n-1])) {
        cout << 1 << "\n";
    } else if(segements == 2 && halal[0] && halal[n-1]) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
}

/*
NOTES:
1 2 3 4 5 6 7 
2 3 1 4 5 7 6
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}


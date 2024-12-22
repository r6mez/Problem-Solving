/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained was fields of dreamless solitude.
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
    vi b(n); cin >> b;
    int sumA = a[n-1];
    int sumB = 0;
    for (int i = 0; i < n-1; i++)
    {
        if(a[i] > b[i+1]) {
            sumA += a[i];
            sumB += b[i+1];
        }
    }
    
    int diff = sumA - sumB;
    cout << diff << "\n";
}

/*
NOTES:
8 2 5 6 2 6
8 2 7 4 3 4

6 + 8 + 
0 + 2 + 
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}


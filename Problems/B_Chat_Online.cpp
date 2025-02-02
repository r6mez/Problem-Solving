/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// B. Chat Online
// URL: https://codeforces.com/contest/469/problem/B
// Time: 1/24/2025, 4:40:09 PM
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
    int p, q, l, r; cin >> p >> q >> l >> r;
    vi x(1005);

    for (int i = 0; i < p; i++){
        int a, b; cin >> a >> b;
        x[a]++; x[b+1]--;
    }

    partial_sum(all(x), x.begin());

    vector<pair<int, int>> cd(q); 
    for (int i = 0; i < q; i++){
        cin >> cd[i].first >> cd[i].second;
    }
    
    
    int total = 0;
    for (int i = l; i <= r; i++){
        vi z(1005);
        for (int j = 0; j < q; j++){
            z[min(cd[j].first + i, 1003)]++;
            z[min(cd[j].second + i + 1, 1003)]--;
        }
        partial_sum(all(z), z.begin());
        for (int j = 0; j <= 1000; j++){
            if(z[j] && x[j]){ 
                total++;
                break;
            }
        }
    }
    
    cout << total << "\n";
}

/*
NOTES:

*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}


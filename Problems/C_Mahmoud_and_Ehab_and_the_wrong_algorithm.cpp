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
    
    if(n < 6){
        cout << -1 << "\n";
    } else {
        cout << "1 2\n";
        cout << "1 3\n";
        cout << "1 4\n";
        for (int i = 5; i <= n; i++){
            cout << "2 " << i << "\n";
        }
    }

    for (int i = 2; i <= n; i++){
        cout << "1 " << i << "\n";
    }
    
}

/*
NOTES:
The first 



The second one
Connect all nodes to 1
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}


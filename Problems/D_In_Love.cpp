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
#define pii  pair<int, int>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){ for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v){ for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

void Ramez() {
    int q; cin >> q;

    multiset<pair<int,int>> minR;

    multiset<pair<int,int>> maxL; 

    for (int i = 0; i < q; i++){
        char c; int l, r;
        cin >> c >> l >> r;
  

        if(c == '+'){
            maxL.emplace(l, r);
            minR.emplace(r, l);
        }
        else {
            maxL.erase(maxL.find({l, r}));
            minR.erase(minR.find({r, l}));
        }

        if (maxL.empty()) {
            cout << "NO\n";
            continue;
        }

        int start = (*minR.begin()).first;
        int end = (*maxL.rbegin()).first;
        
        
        if(start < end) cout << "YES\n";
        else cout << "NO\n";
    }
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


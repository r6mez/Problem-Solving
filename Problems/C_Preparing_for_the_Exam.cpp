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

// Got hacked on this solution, It's fast + solve the problem 
// in 10 minutes but what a sad story huh ?
void Ramez() {
    ll n, m, k; cin >> n >> m >> k;
    vi a(m); cin >> a;
    vi q(k); cin >> q;

    set<int> dontKnow;
    for (int i = 1; i <= n; i++){
        if(!binary_search(all(q), i)){
            dontKnow.emplace(i);
        }
    }

    // cout << dontKnow.size() << "\n";
    
    if(dontKnow.size() >= 2){
        string ans(m, '0');
        cout << ans << "\n";
    } else if (dontKnow.size() == 0){
        string ans(m, '1');
        cout << ans << "\n";
    } else {
        string ans(m, '0');
        int question = *(dontKnow.begin());
        auto it = lower_bound(all(a), question);
        if(it != a.end() && *it == question){
            int i = it - a.begin();
            ans[i] = '1';
        }
        cout << ans << "\n";
    }
}

void Ramez2(){
    ll n, m, k; cin >> n >> m >> k;
    vll a(m); cin >> a;
    vll q(k); cin >> q;

    vll freq(n+1);
    for (int i = 0; i < k; i++){
        freq[q[i]]++;
    }
    
    vll unknown;
    for (int i = 1; i <= n; i++){
        if(freq[i] == 0) unknown.push_back(i); 
    }

    if(unknown.size() == 0){
        string ans(m, '1');
        cout << ans << "\n";
    } else if (unknown.size() >= 2){
        string ans(m, '0');
        cout << ans << "\n";
    } else {
        string ans(m, '0');
        ll question = unknown[0];
        auto it = lower_bound(all(a), question);
        if(it != a.end() && *it == question){
            int i = it - a.begin();
            ans[i] = '1';
        }
        cout << ans << "\n";
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


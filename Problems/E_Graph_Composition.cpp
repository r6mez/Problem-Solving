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
    int n, m1, m2; cin >> n >> m1 >> m2;
    set<pair<int, int>> s1, s2;
    for (int i = 0; i < m1; i++){
        int u, v; cin >> u >> v;
        if(v < u) swap(u, v);
        s1.insert({u, v});
        cout << u << " " << v << "\n";
    }

    cout << "\n";

    for (int i = 0; i < m2; i++){
        int u, v; cin >> u >> v;
        if(v < u) swap(u, v);
        s2.insert({u, v});
        cout << u << " " << v << "\n";
    }

    int ops = 0;
    for(pair<int, int> edge : s1){
        if(s2.count(edge) == 0){
            ops++;
            s1.erase(edge);
        }
    }
    
    for(pair<int, int> edge : s2){
        if(s1.count(edge) == 0){
            ops++;
            s1.insert(edge);
        }
    }

    cout << ops << "\n";
}

/*
1
20 19 6
5 7
2 9
6 8
1 4
3 6
3 14
8 10
4 11
1 5
1 3
11 17
11 15
7 18
2 13
1 2
7 12
7 19
7 20
4 16

6 19
7 15
6 10
1 20
3 10
12 15


*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}


/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// D. Number into Sequence
// URL: https://codeforces.com/problemset/problem/1454/D
// Time: 2/2/2025, 6:41:22 PM
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi   vector<int>
#define pii  pair<int, int>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int  dx[] = { -1,   1,   0,   0 }; int  dy[] = { 0,   0,  -1,   1 }; char dir[] = { 'U', 'D', 'L', 'R' };
int MOD = 1000000007;

vector<pii> getPrimeFactors(int n) {
    vector<pii> primeFactors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) n /= i, count++;
            primeFactors.push_back({i, count});
        }
    }
    if (n > 1) primeFactors.push_back({n, 1});
    return primeFactors;
}

void Ramez() {
    int n; cin >> n;
    vi result;

    vector<pii> prfc = getPrimeFactors(n);

    pii maxFactor = {0, INT_MIN};
    for (int i = 0; i < prfc.size(); i++){
        cout << prfc[i].first << " " << prfc[i].second << "\n";
        if(maxFactor.second < prfc[i].second){
            maxFactor = prfc[i];
        }
    } 

    for (int i = 1; i < maxFactor.second; i++){
        result.push_back(maxFactor.first);
    }
    
    
    int newN = maxFactor.first;
    for (int i = 0; i < prfc.size(); i++){
        if(maxFactor == prfc[i]) continue;
        for (int j = 0; j < prfc[i].second; j++){
            newN *= prfc[i].first;
        }
    }

    result.push_back(newN);

    cout << result.size() << "\n";
    cout << result << "\n";
}

/*
NOTES:
360
3
2 2 2 3 3 5

2 2 6 15

9876543210
4938271605

2
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}


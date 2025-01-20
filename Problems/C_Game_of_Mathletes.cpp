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
    int n, k; cin >> n >> k;
    vi a(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }
    
    int count = 0;
    for (int i = 0; i < n; i++){
        if(freq[a[i]] && freq[k - a[i]] - (a[i] == k - a[i])){
            // cout << a[i] << " " << k - a[i] << "\n";
            count++;
            freq[a[i]]--;
            freq[k-a[i]]--;
        } 
    }
    
    cout << count << "\n";
}

/*
NOTES:
16 9
1 1 2 3 3 3 4 5 5 5 6 7 8 9 9 9 
2 7
1 8
6 3 
5 4 
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}


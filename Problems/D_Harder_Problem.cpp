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
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

void Ramez() {
    int n; cin >> n;
    vi a(n), b(n); cin >> a;
    map<int, int> freq;

    int j = 0;
    for (int i = 0; i < n; i++){
        if(freq.count(a[i]) == 0){
            b[j] = a[i];
            freq[b[j]]++;
            j++;
        }
    }
    
    int num = 1;
    while(j < n){
        while(freq.count(num) != 0){
            num++;
        }
        b[j] = num;
        freq[b[j]]++;
        j++;
    }

    cout << b << "\n";
}

/*
NOTES:
4 5 5 5 1 1 2 1
4 6 6 1 1 2 2 1 

4 5 5 5 1 1 2 1
4 5 5 5 1 1 2 1 
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}


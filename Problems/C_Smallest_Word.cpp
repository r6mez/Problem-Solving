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
    string s; cin >> s;
    int n = s.size();
    vi a(n);
    for (int i = 0; i < n-1; i++){
        if(s[i] == 'b' && s[i+1] == 'a'){
            a[i] = 1;
            while(i < n && s[i+1] == 'a') i++;
            a[i] = 1;
        }
    }
    cout << a << "\n";
}

/*
NOTES:
aaaaa
0 0 0 0 0 0

bbab
0 0 1 0

0 1 1 1 1 0 0 1 1 1 1 
b b a b a b b b a b a 
a b b b a b b b a b a 
b b b a a b b b a b a 
a a b b b b b b a b a 
b b b b b b a a a b a 
a a a b b b b b b b a 
b b b b b b b a a a a 
a a a a b b b b b b b

0 0 1 0 1 0 1 1
a b b a a b b a
b b a a a b b a 
a a a b b b b a
b b b b a a a a
a a a a b b b b
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}


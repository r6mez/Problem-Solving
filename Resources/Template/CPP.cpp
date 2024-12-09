/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained was fields of dreamless solitude.
*/
#include <bits/stdc++.h>
#define ll   long long
#define vi   vector<int>
#define vll  vector<ll>
#define pll  pair<ll, ll>
#define all(v)  v.begin(), v.end()
using namespace std;
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v);
template<typename T> istream& operator>>(istream& is, vector<T>& v);
const int MOD = 1000000007;

void Ramez() {

}

/*
NOTES:

*/

void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i << ' '; return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v){
    for (auto& i : v) is >> i; return is;
}
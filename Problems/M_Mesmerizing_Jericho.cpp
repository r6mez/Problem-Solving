/*
"You’ve changed so much Thorfinn,
that anger in your eyes is gone, i’m glad"
*/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define ll   long long
#define ull  unsigned ll
#define vi   vector<int>
#define vvi  vector<vi>
#define vll  vector<ll>
#define vvll vector<vll>
#define vs   vector<string>
#define pii  pair<int, int>
#define pll  pair<ll, ll>
using namespace std;
#define all(v)  v.begin(), v.end()
#define makeUnique(v)  v.erase(unique(all(v)), v.end())
vvll prefixSum2D(vvll& a); ll sumOfSquare(ll x1, ll y1, ll x2, ll y2, vvll& a);
vll getDivisors(ll n); bool isPrime(ll n); bool isPrime(ll n, vll& primes);
vector<pll> getPrimeFactors(ll n); vll linearSieve(ll n); ll nPr(ll n, ll r); ll nCr(ll n, ll r);
ll pwmod(ll b, ll p); void buildFacAndInvFac(); ll nCr2(ll n, ll r);
ll add(ll a, ll b); ll mul(ll a, ll b); ll sub(ll a, ll b); ll divide(ll a, ll b);
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v);
template<typename T> istream& operator>>(istream& is, vector<T>& v);
void FastIO(); void UseFile();
const int MOD = 1000000007;

/*
Evolution has a destination not to combat nature 
but to supersede it, the final glorious evolution.
*/

void Ramez() {
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;

    int start = 0;

    for (int i = 0; i < q; i++){
        int x, j; cin >> x >> j;
        if(x == 2){
            cout << s[(start + j-1)%n] << "\n";
        } else {
            start = (start + j)%n;
        }
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

void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i << ' ';
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v)
{
    for (auto& i : v) is >> i;
    return is;
}

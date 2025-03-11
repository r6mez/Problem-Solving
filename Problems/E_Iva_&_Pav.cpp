// -------------------- Ramez -------------------------
// سَأَحمِلُ روحي عَلى راحَتي    وَأُلقي بِها في مَهاوي الرَدى
// فَإِمّـا حَــيــاةٌ تُسِــرُّ الـصَديقَ    وَإِمّــا مَمــاتٌ يُغــيظُ العِــدى
// ----------------------------------------------------
// Contest: Codeforces Round 900 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/1878/E
// Memory Limit: 256
// Time Limit: 5000
// Start: Tue 01 Oct 2024 09:02:51 PM EEST 
#include <climits>
#ifdef RAMEZ
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif
#include <bits/stdc++.h>
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
vll getDivisors(ll n); bool isPrime(ll n); bool isPrime(ll n, vll &primes);
vector<pll> getPrimeFactors(ll n); vll linearSieve(ll n); ll nPr(ll n, ll r); ll nCr(ll n, ll r);
ll pwmod(ll b, ll p); void buildFacAndInvFac(); ll nCr2(ll n, ll r);
ll add(ll a, ll b); ll mul(ll a, ll b); ll sub(ll a, ll b); ll divide(ll a, ll b);
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v);
template<typename T> istream& operator>>(istream& is, vector<T>& v);
void FastIO(); void UseFile();
const int MOD = 1000000007;


class SegmentTree {
public:
    int size;
    vector<int> ands;

    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        ands.assign(2 * size, -1);  // Initialize with -1 for AND operation.
    }

    void build(const vi& a) {
        build(a, 0, 0, size);
    }

    int sumSeg(int l, int r) {
        return sumSeg(l, r, 0, 0, size);
    }

private:
    void build(const vi& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                ands[x] = a[lx];
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);
        ands[x] = ands[2 * x + 1] & ands[2 * x + 2];
    }

    int sumSeg(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return -1;  // Return -1 for AND operation.
        if (lx >= l && rx <= r) return ands[x];
        int mid = (lx + rx) / 2;
        int left = sumSeg(l, r, 2 * x + 1, lx, mid);
        int right = sumSeg(l, r, 2 * x + 2, mid, rx);
        return left & right;
    }
};

bool can(int l, int r, int k, SegmentTree &st){
    return st.sumSeg(l, r+1) >= k;  // Ensure sumSeg checks the full range [l, r]
}

void solve(){
    int n; cin >> n;
    vi a(n); 
    for (int i = 0; i < n; i++) cin >> a[i];

    SegmentTree st(n);
    st.build(a);
    
    int q; cin >> q;
    while(q--){
        int s, k; cin >> s >> k;
        int l = s-1, r = n-1;

        // Binary search for the largest r where AND >= k
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(can(s-1, mid, k, st)){
                l = mid; 
            } else {
                r = mid - 1;
            }
        }
        
        // After binary search, check final result
        if(can(s-1, r, k, st)) cout << r+1 << " ";  // Adjust output to 1-based index
        else cout << "-1 ";
    }
    cout << endl;
}


/*
NOTES:

*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
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

vvll prefixSum2D(vvll& a) {
    vvll b(a.size(), vll(a[0].size()));
    for (int i = 0; i < a.size(); i++) {
        partial_sum(all(a[i]), b[i].begin());
    }
    for (int i = 0; i < a[0].size(); i++)
    {
        for (int j = 1; j < a.size(); j++)
        {
            b[j][i] += b[j - 1][i];
        }
    }
    return b;
}

ll sumOfSquare(ll x1, ll y1, ll x2, ll y2, vvll& a) {
    return (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1]) + a[x1 - 1][y1 - 1];
}

vll getDivisors(ll n){
  vll divs;
  for (ll i = 1; i*i <= n; i++) {
    if(n%i == 0) {
      divs.push_back(i);
      if(i*i != n) divs.push_back(n/i);
    }
  }
  return divs;
}

bool isPrime(ll n){
  if (n == 2) return true;
  if (n == 1 or n%2 == 0) return false;
  for (ll i = 3; i*i <= n; i += 2) {
    if(n%i == 0) return false;
  }
  return true;
}

// Function to check if a number is prime by testing divisibility using primes up to sqrt(n)
bool isPrime(ll n, vll& primes) {
    if (n < 2) return false;
    for (ll p : primes) {
        if (p * p > n) break;
        if (n % p == 0) return false;
    }
    return true;
}

vector<pll> getPrimeFactors(ll n){
  vector<pll> primeFactors;
  for (ll i = 2; i*i <= n; i++) {
    if(n%i == 0) {
      int count = 0;
      while(n%i == 0) n /= i, count++;
      primeFactors.push_back({i,count}); 
    } 
  }
  if(n > 1) primeFactors.push_back({n,1});
  return primeFactors;
}

ll add(ll a, ll b) {return ((a%MOD) + (b%MOD))%MOD;}
ll mul(ll a, ll b) {return ((a%MOD) * (b%MOD))%MOD;}
ll sub(ll a, ll b) {return ((((a%MOD) - (b%MOD))%MOD)+MOD)%MOD;}
ll divide(ll a, ll b) { return mul(a, pow(b, MOD-2)); }

vll linearSieve(ll n){
  vector<bool> isPr(n+1, 1); 
  vll primes;
  isPr[0] = isPr[1] = 0;

  for (ll i = 2; i <= n; i++) {
    if(isPr[i]) primes.push_back(i);
    for(ll p : primes){
      if(i * p >= n+1) break;
      isPr[i*p] = 0;
      if(i%p == 0) break;
    }
  }

  return primes;
}

ll nPr(ll n, ll r){
	ll ans = 1;
	for (ll i = (n - r) + 1; i <= n; i++){
		ans *= i;
		ans %= MOD;
	}
	return ans;
}

ll nCr(ll n, ll r){
	ll ans = 1;
	ll div = 1; // r! 
	for (ll i = r + 1; i <= n; i++){
		ans = ans * i;
		ans /= div;
		div++;
	}
	return ans;
}

const ll N = 1e6 + 2;

vll fac(N), inv(N);

ll pwmod(ll b, ll p) {
    if (!p) return 1LL;
    ll ret = pwmod(b, p >> 1LL);
    ret = mul(ret,ret);
    if (p & 1LL)
        ret = mul(ret,b);
    return ret;
}
 
void buildFacAndInvFac(){
    fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = mul(fac[i - 1],i);
    }
    inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        inv[i] = pwmod(fac[i],MOD-2);
    }
}
 
ll nCr2(ll n, ll r){
    if(r > n) return 0;
    return mul(mul(fac[n],inv[n - r]),inv[r]);
}



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
    ll n, l, r; cin >> n >> l >> r;
    vll a(n); cin >> a;

    if(n == 1){
        cout << "0\n";
        return;
    }

    sort(all(a));
    
    ll count = 0;
    for (int i = 0; i < n; i++){
        auto it1 = lower_bound(a.begin()+i+1, a.end(), l - a[i]);
        if(it1 == a.end()) continue;
        ll start = it1 - a.begin();

        auto it2 = upper_bound(a.begin()+i+1, a.end(), r - a[i]);
        ll end;
        if(it2 == a.end()) end = n-1;
        else {
            it2--;
            end = it2 - a.begin();
        }

        count += end - start + 1;
    }
    

    cout << count << "\n";
}

/*
NOTES:
5 5 8
1 2 3 4 5
2 3 
2 4
2 5
1 4 
1 5

a[i]+a[j] >= l


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

vll getDivisors(ll n) {
    vll divs;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i * i != n) divs.push_back(n / i);
        }
    }
    return divs;
}

bool isPrime(ll n) {
    if (n == 2) return true;
    if (n == 1 || n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
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

vector<pll> getPrimeFactors(ll n) {
    vector<pll> primeFactors;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) n /= i, count++;
            primeFactors.push_back({ i,count });
        }
    }
    if (n > 1) primeFactors.push_back({ n,1 });
    return primeFactors;
}

ll pwmod(ll b, ll p) {
    if (!p) return 1LL;
    ll ret = pwmod(b, p >> 1LL);
    ret = mul(ret, ret);
    if (p & 1LL)
        ret = mul(ret, b);
    return ret;
}

ll add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll sub(ll a, ll b) { return ((((a % MOD) - (b % MOD)) % MOD) + MOD) % MOD; }
ll divide(ll a, ll b) { return mul(a, pwmod(b, MOD - 2)); }

vll linearSieve(ll n) {
    vector<bool> isPr(n + 1, 1);
    vll primes;
    isPr[0] = isPr[1] = 0;

    for (ll i = 2; i <= n; i++) {
        if (isPr[i]) primes.push_back(i);
        for (ll p : primes) {
            if (i * p >= n + 1) break;
            isPr[i * p] = 0;
            if (i % p == 0) break;
        }
    }

    return primes;
}

ll nPr(ll n, ll r) {
    ll ans = 1;
    for (ll i = (n - r) + 1; i <= n; i++) {
        ans *= i;
        ans %= MOD;
    }
    return ans;
}

ll nCr(ll n, ll r) {
    ll ans = 1;
    ll div = 1; // r! 
    for (ll i = r + 1; i <= n; i++) {
        ans = ans * i;
        ans /= div;
        div++;
    }
    return ans;
}

const ll SizeMax = 1e6 + 2;

vll fac(0), inv(0);

void buildFacAndInvFac() {
    fac.resize(SizeMax);
    inv.resize(SizeMax);
    fac[0] = 1;
    for (int i = 1; i < SizeMax; ++i) {
        fac[i] = mul(fac[i - 1], i);
    }
    inv[0] = 1;
    for (int i = 1; i < SizeMax; ++i) {
        inv[i] = pwmod(fac[i], MOD - 2);
    }
}

ll nCr2(ll n, ll r) {
    if (r > n) return 0;
    return mul(mul(fac[n], inv[n - r]), inv[r]);
}

class SegmentTree {
public:
    int size;
    vector<ll> sums, mins, maxs;

    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0LL);
        mins.assign(2 * size, LLONG_MAX);
        maxs.assign(2 * size, LLONG_MIN);
    }

    void build(const vi& a) {
        build(a, 0, 0, size);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }

    ll sumSeg(int l, int r) {
        return sumSeg(l, r, 0, 0, size);
    }

    ll minSeg(int l, int r) {
        return minSeg(l, r, 0, 0, size);
    }

    ll maxSeg(int l, int r) {
        return maxSeg(l, r, 0, 0, size);
    }

    ll firstElementAtLeastX(int x) {
        return firstElementAtLeastX(x, 0, 0, size);
    }

private:
    void build(const vi& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                sums[x] = a[lx];
                mins[x] = a[lx];
                maxs[x] = a[lx];
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
        maxs[x] = max(maxs[2 * x + 1], maxs[2 * x + 2]);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = v;
            mins[x] = v;
            maxs[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            update(i, v, 2 * x + 1, lx, mid);
        }
        else {
            update(i, v, 2 * x + 2, mid, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
        maxs[x] = max(maxs[2 * x + 1], maxs[2 * x + 2]);
    }

    ll sumSeg(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return sums[x];
        int mid = (lx + rx) / 2;
        ll left = sumSeg(l, r, 2 * x + 1, lx, mid);
        ll right = sumSeg(l, r, 2 * x + 2, mid, rx);
        return left + right;
    }

    ll minSeg(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return LLONG_MAX;
        if (lx >= l && rx <= r) return mins[x];
        int mid = (lx + rx) / 2;
        ll left = minSeg(l, r, 2 * x + 1, lx, mid);
        ll right = minSeg(l, r, 2 * x + 2, mid, rx);
        return min(left, right);
    }

    ll maxSeg(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return LLONG_MIN;
        if (lx >= l && rx <= r) return maxs[x];
        int mid = (lx + rx) / 2;
        ll left = maxSeg(l, r, 2 * x + 1, lx, mid);
        ll right = maxSeg(l, r, 2 * x + 2, mid, rx);
        return max(left, right);
    }


    ll firstElementAtLeastX(int x, int currentNode, int l, int r) {
        if (maxs[currentNode] < x) {
            return -1;
        }

        if (r - l == 1) { // we're in the bottom of the tree
            return l;
        }

        int mid = (l + r) / 2;
        int res = firstElementAtLeastX(x, 2 * currentNode + 1, l, mid);
        if (res == -1) {
            res = firstElementAtLeastX(x, 2 * currentNode + 2, mid, r);
        }
        return res;
    }
};

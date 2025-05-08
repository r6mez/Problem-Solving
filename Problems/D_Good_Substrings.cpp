/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Good Substrings
// URL: https://codeforces.com/contest/271/problem/D
// Time: 5/6/2025, 7:07:51 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

constexpr int H = 2;
typedef array<int, H> val;
vector<val> B;
const val M = {
    1000000007,
    1444444447,
    // 998244353,
    // 1000000009,
};

val tmp;

val operator*(const val& a, const val& b) {
    for (int i = 0; i < H; i++)
        tmp[i] = a[i] * b[i] % M[i];
    return tmp;
}

val operator-(const val& a, const val& b) {
    for (int i = 0; i < H; i++)
        tmp[i] = (a[i] - b[i] + M[i]) % M[i];
    return tmp;
}

val operator+(const val& a, const val& b) {     
    for (int i = 0; i < H; i++)
        tmp[i] = (a[i] + b[i]) % M[i];
    return tmp;
}

val getval(int x) {
    for (int i = 0; i < H; i++)
        tmp[i] = x % M[i];
    return tmp;
}

void setB(int n) {
    if (B.size() == 0) {
        mt19937 rng(random_device{}());
        B.assign(2, getval(1));
        for (int i = 0; i < H; i++)
            B.back()[i] = uniform_int_distribution<int>(1, M[i] - 1)(rng);
    }
    while ((int)B.size() <= n)
        B.push_back(B.back() * B[1]);
}

struct Hash {
    vector<val> h;

    Hash(const string& s) : Hash(vector<int>(s.begin(), s.end())) {}

    Hash(const vector<int>& s) {
        vector<val> v;
        for (auto x : s)
            v.push_back(getval(x));
        *this = Hash(v);
    }

    Hash(const vector<val>& s) : h(s.size() + 1) {
        setB(s.size());
        for (int i = 0; i < (int)s.size(); i++)
            h[i + 1] = h[i] * B[1] + s[i];
    }

    val get(int l, int r) { return h[r + 1] - h[l] * B[r - l + 1]; }
};

struct val_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(const val& v) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(v[0] + FIXED_RANDOM) ^
            (splitmix64(v[1] + FIXED_RANDOM) >> 1);
    }
};

void Ramez() {
    string s, v; cin >> s >> v;
    int k; cin >> k;

    int n = s.size();
    Hash h(s);

    unordered_set<val, val_hash> se;

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (v[s[j] - 'a'] == '0')
                cnt++;
            if (cnt > k) {
                break;
            }
            se.insert(h.get(i, j));
        }
    }

    cout << se.size() << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}
/*
    But when every equation was solved aint that remained
    were fields of dreamless solitude.
*/
// B. Palindromic Numbers
// URL: https://codeforces.com/problemset/problem/1700/B
// Time: 7/16/2025, 11:47:24 AM
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

template <int base = 10> class bigint {
public:
    vector<int> digits;

    bigint(unsigned int value = 0) { set_value(value); }

    bigint(string s) {
        digits.resize(s.size());
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            digits[i] = s[(int)s.size() - 1 - i] - '0';
        }
    }

    template <typename RandomIt> bigint(RandomIt begin, RandomIt end) {
        digits.assign(begin, end);
    }

    void set_value(int value) {
        digits.clear();
        while (value) {
            digits.push_back(value % base);
            value /= base;
        }
    }

    int size() const { return digits.size(); }

    void trim() {
        while (digits.back() == 0 && digits.size() > 1)
            digits.pop_back();
    }

    int& operator[](int i) { return digits[i]; }

    int operator[](int i) const { return digits[i]; }

    void operator*=(const bigint& rhs) {
        vector<int> res(size() + rhs.size() + 1);
        for (int i = 0; i < size(); i++) {
            for (int j = 0; j < rhs.size(); j++) {
                res[i + j] += digits[i] * rhs[j];
            }
        }
        for (int i = 0; i < (int)res.size() - 1; i++) {
            res[i + 1] += res[i] / base;
            res[i] %= base;
        }
        digits = res;
        trim();
    }

    void operator+=(const bigint& rhs) {
        digits.resize(max(size(), rhs.size()) + 1);
        int i;
        for (i = 0; i < rhs.size(); i++) {
            digits[i] += rhs[i];
            if (digits[i] >= base) {
                digits[i + 1] += digits[i] / base;
                digits[i] %= base;
            }
        }
        while (i < (int)digits.size() - 1 && digits[i] >= base) {
            digits[i + 1] = digits[i] / base;
            digits[i] %= base;
        }
        trim();
    }
    void operator-=(const bigint& rhs) {
        int borrow = 0;
        for (int i = 0; i < (int)digits.size(); i++) {
            digits[i] -= borrow + (i < rhs.size() ? rhs[i] : 0);
            if (digits[i] < 0) {
                digits[i] += base;
                borrow = 1;
            }
            else {
                borrow = 0;
            }
        }
        trim();
    }
    bigint operator-(const bigint& rhs) const {
        bigint result = *this;
        result -= rhs;
        return result;
    }
    void operator%=(int mod) {
        int p = 1;
        int res = 0;
        for (int i = 0; i < size(); i++) {
            res = (res + p * digits[i] % mod) % mod;
            p = p * base % mod;
        }
        *this = res;
    }

    friend bool operator==(bigint& lhs, bigint& rhs) {
        return lhs.digits == rhs.digits;
    }

    friend bool operator!=(bigint& lhs, bigint& rhs) {
        return lhs.digits != rhs.digits;
    }

    friend bool operator<(bigint& lhs, bigint& rhs) {
        if (lhs.size() != rhs.size())
            return lhs.size() < rhs.size();
        for (int i = lhs.size() - 1; i >= 0; i--) {
            if (lhs[i] < rhs[i])
                return true;
            if (lhs[i] > rhs[i])
                return false;
        }
        return false; // equal
    }

    friend ostream& operator<<(ostream& os, const bigint& bi) {
        for (int i = bi.size() - 1; i >= 0; i--)
            os << bi[i];
        return os;
    }
};

void Ramez() {
    int n; cin >> n;
    string s; cin >> s;
    string ones(n + 1, '1');
    string nines(n, '9');

    
    bigint b(s);
    bigint ans = bigint(ones) - b;
    bigint ans2 = bigint(nines) - b;

    if (ans.size() == n)  cout << ans << "\n";
    else if (ans2.size() == n) cout << ans2 << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}
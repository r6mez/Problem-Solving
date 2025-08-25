/*
    One day, I'm gonna grow wings
*/
// D. From 1 to Infinity
// URL: https://codeforces.com/contest/2132/problem/D
// Time: 8/21/2025, 6:51:54 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> auto& operator<<(auto& o, vector<T>& v) { for (auto& e : v) o << e << ' '; return o; }
template<typename T> auto& operator>>(auto& i, vector<T>& v) { for (auto& e : v) i >> e; return i; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int k; cin >> k;

    vi p10(18), sum(18);
    p10[0] = 1; 
    for (int i = 1; i <= 17; ++i) {
        p10[i] = p10[i - 1] * 10;
        sum[i] = 45 * i * p10[i - 1];
    }

    map<int, int> dp;
    function<int(int)> calc = [&](int n) -> int {
        if (n < 10) return n * (n + 1) / 2;
        
        if (dp.count(n)) return dp[n];
    
        string s = to_string(n);
        int p = s.size();
        int msd = s[0] - '0';
        int rem = n % p10[p - 1];

        int res = sum[p - 1];
        if (msd > 1) {
            res += (msd * (msd - 1) / 2) * p10[p - 1];
            res += (msd - 1) * sum[p - 1];
        }

        res += msd * (rem + 1);
        res += calc(rem);

        return dp[n] = res;
    };

    int total_sum = 0, d = 1;
    while (true) {
        int count_d_digit_nums = 9 * p10[d - 1];
        int digits_in_block = count_d_digit_nums * d;

        if (k > digits_in_block) {
            k -= digits_in_block;
            total_sum += sum[d] - sum[d - 1];
            d++;
        }
        else {
            int start_num = p10[d - 1];
            int num_full = k / d;

            if (num_full > 0) {
                int end_num = start_num + num_full - 1;
                total_sum += calc(end_num) - calc(start_num - 1);
            }

            int rem_digits = k % d;
            if (rem_digits > 0) {
                int next_num = start_num + num_full;
                string s_next = to_string(next_num);
                for (int i = 0; i < rem_digits; ++i) {
                    total_sum += s_next[i] - '0';
                }
            }
            break;
        }
    }
    cout << total_sum << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
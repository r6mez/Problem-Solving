    /*
        I thought I could bring an end to the world's suffering,
        But when every equation was solved all that remained
        were fields of dreamless solitude.
    */
    // H. Maximal AND
    // URL: https://codeforces.com/contest/1669/problem/H
    // Time: 4/3/2025, 1:23:01 PM
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

    void Ramez() {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        vector<int> zeros(32, 0);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            bitset<31> b = arr[i];
            for (int j = 0; j < 31; ++j) zeros[j] += (b[j] == 0);
        }
        vector<int> idx;
        for (int i = 30; i >= 0; --i) {
            if (zeros[i] <= k) {
                idx.push_back(i);
                k -= zeros[i];
            }
        }
        for (int id : idx) {
            for (int i = 0; i < n; ++i) {
                arr[i] |= (1 << id);
            }
        }
        int ans = arr[0];
        for (int i = 1; i < n; ++i) ans &= arr[i];
        cout << ans << '\n';
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
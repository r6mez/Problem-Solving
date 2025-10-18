/*
    One day, I'm gonna grow wings
*/
// G. Buratsuta 3
// URL: https://codeforces.com/contest/2149/problem/G
// Time: 9/25/2025, 7:39:37 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) : arr(arr) {
        if (arr.size() == 0) return ;
        for (int i = 0; i < arr.size(); ++i) {
            if (mp.find(arr[i]) == mp.end()) mp[arr[i]] = vector<int>(1, i);
            else mp[arr[i]].push_back(i);
        }
        node.resize(4 * arr.size(), -1);
        build(0, arr.size() - 1, 1);
    }
    
    int query(int left, int right, int threshold) {
        // index, occur
        pair<int, int> ret = query(left, right, 0, arr.size() - 1, 1);
        if (ret.second >= threshold) return ret.first;
        else return -1;
    }
private:
    void build(int st, int ed, int cur) {
        if (st == ed) {
            node[cur] = arr[st];
            return ;
        }
        int mid = (st + ed) / 2;
        build(st, mid, cur * 2);
        build(mid + 1, ed, cur * 2 + 1);
        if (node[cur * 2] != -1 && count_occur(node[cur * 2], st, ed) * 2 > ed - st + 1) {
            node[cur] = node[cur * 2];
        }
        else if (node[cur * 2 + 1] != -1 && count_occur(node[cur * 2 + 1], st, ed) * 2 > ed - st + 1) {
            node[cur] = node[cur * 2 + 1];
        }
        return ;
    }

    pair<int, int> query(const int &l, const int &r, int st, int ed, int cur) {
        if (st > r || ed < l) {
            return make_pair(-1, -1);
        }
        if (l <= st && ed <= r) {
            if (node[cur] == -1) return make_pair(-1, -1);
            int occ = count_occur(node[cur], l, r);
            if (occ * 2 > r - l + 1) return make_pair(node[cur], occ);
            else return make_pair(-1, -1);
        }
        int mid = (st + ed) / 2;
        if (l <= mid) {
            pair<int, int> ret_l = query(l, r, st, mid, cur * 2);
            if (ret_l.first != -1) return ret_l;
        }
        if (r > mid) {
            pair<int, int> ret_r = query(l, r, mid + 1, ed, cur * 2 + 1);
            if (ret_r.first != -1) return ret_r;
        }
        return make_pair(-1, -1);
    }

    int count_occur(int val, int left, int right) {
        int st_idx = lower_bound(mp[val].begin(), mp[val].end(), left)
                - mp[val].begin();
        int ed_idx = upper_bound(mp[val].begin(), mp[val].end(), right)
                - mp[val].begin();
        return ed_idx - st_idx;
    }

    unordered_map<int, vector<int>> mp;
    vector<int> arr, node;
};

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;
    MajorityChecker mc(a);
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        int len = r - l + 1;
        int threshold = len / 3;
        cout << mc.query(l, r, threshold) << ' ';
    }
    cout << '\n';
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
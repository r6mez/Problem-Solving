// -------------------- Ramez -------------------------
// سَأَحمِلُ روحي عَلى راحَتي    وَأُلقي بِها في مَهاوي الرَدى
// فَإِمّـا حَــيــاةٌ تُسِــرُّ الـصَديقَ    وَإِمّــا مَمــاتٌ يُغــيظُ العِــدى
// ----------------------------------------------------
// problem: B. Volcano of Venus
// URL: https://codeforces.com/gym/536143/problem/B  
// Start: 8/10/2024, 2:11:33 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <numeric>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <unordered_map>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v)  v.begin(), v.end()
struct SegTree; const int MOD = 1000000007;
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v);
template<typename T> istream& operator>>(istream& is, vector<T>& v);
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }

int main() {
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) {
        int n, cnt = 0; cin >> n;
        int a[n];
        vi mp(n);
        cin >> a[0];
        mp[0] = cnt;
        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
            if (a[i] != a[i - 1])
            {
                cnt++;
            }
            mp[i] = cnt;
        }
        int m; cin >> m;

        for (int i = 0; i < m; i++)
        {
            int x, y; cin >> x >> y;
            if (mp[x - 1] == mp[y - 1])
            {
                cout << -1 << " " << -1 << endl;
            }
            else
            {
                int l = x, r = y - 1, midl = (l + r) / 2, midr = (l + r) / 2;
                while (l <= r)
                {
                    if (a[l] != a[x - 1])
                    {
                        cout << x << " " << l + 1 << endl;
                        break;
                    }
                    else if (a[r] != a[x - 1])
                    {
                        cout << x << " " << r + 1 << endl;
                        break;
                    }
                    else if (a[midl] != a[x - 1])
                    {
                        cout << x << " " << midl + 1 << endl;
                        break;
                    }
                    else if (a[midr] != a[x - 1])
                    {
                        cout << x << " " << midr + 1 << endl;
                        break;
                    }
                    midl++;
                    midr--;
                    r--;
                    l++;
                }
            }
        }

    }
    return 0;
}
// int main() {
//     // freopen("file.in", "r", stdin);
//     // freopen("file.out", "w", stdout);
//     FastIO();
//     int t = 1;
//     cin >> t;
//     while (t--) {
//         int n; cin >> n;
//         vi a(n); cin >> a;
//         int m; cin >> m;
//         unordered_map<pii, pii, pair_hash> dp;


//         for (int i = 0; i < m; i++)
//         {
//             int x, y; cin >> x >> y;
//             x--; y--;
//             if (dp.find({ x, y }) != dp.end()) {
//                 cout << dp[{x - 1, y - 1}].first << " " << dp[{x - 1, y - 1}].second << "\n";
//             }
//             else {
//                 if (a[x] != a[y]) {
//                     dp[{x, y}] = { x + 1, y + 1 };
//                 }
//                 else {
//                     int newY = y;
//                     while (newY > x && a[x] == a[newY]) newY--;
//                     if (a[x] != a[newY]) dp[{x, y}] = { x + 1, newY + 1 };
//                     else dp[{x, y}] = { -1, -1 };
//                 }
//                 cout << dp[{x, y}].first << " " << dp[{x, y}].second << "\n";
//             }
//         }

//     }
//     return 0;
// }

/*
NOTES:

*/

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

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i << ' ';
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v)
{
    for (auto& i : v) is >> i;
    return is;
}

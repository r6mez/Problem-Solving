// -------------------- Ramez -------------------------
// سَأَحمِلُ روحي عَلى راحَتي    وَأُلقي بِها في مَهاوي الرَدى
// فَإِمّـا حَــيــاةٌ تُسِــرُّ الـصَديقَ    وَإِمّــا مَمــاتٌ يُغــيظُ العِــدى
// ----------------------------------------------------
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1188
// Memory Limit: 512
// Time Limit: 1000
// Start: Mon 02 Sep 2024 09:04:58 PM EEST 
#ifdef ALGOAT
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif
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
#define ll   long long
#define ull  unsigned long long
#define vi   vector<int>
#define vvi  vector<vi>
#define vll  vector<long long>
#define vvll vector<vll>
#define vs   vector<string>
#define pii  pair<int, int>
#define pll  pair<ll, ll>
#define F first
#define S second
using namespace std;
struct   SegTree;
const int MOD = 1000000007;
#define all(v)  v.begin(), v.end()
#define makeUnique(v)  v.erase(unique(all(v)), v.end())
vector<vll> prefixSum2D(vector<vll>& a);
ll sumOfSquare(int x1, int y1, int x2, int y2, vector<vll>& a);
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v);
template<typename T> istream& operator>>(istream& is, vector<T>& v);
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }

#define sz(x) (x).size()

string s;
int m;
set<int> dif;
multiset<int> ret;

void modify(int x) {
	if (x == 0 || x == sz(s)) return;
	auto it = dif.find(x);
	if (it != end(dif)) {  // x is currently present in dif, remove it
		int a = *prev(it), b = *next(it);
		ret.erase(ret.find(x - a)), ret.erase(ret.find(b - x));  // update ret
		ret.insert(b - a);
		dif.erase(it);             // remove x from dif
	} else {                       // x is not currently in dif, insert it
		it = dif.insert(x).first;  // insert x into dif
		// it = iterator corresponding to x
		int a = *prev(it), b = *next(it);
		ret.erase(ret.find(b - a));  // update ret
		ret.insert(x - a), ret.insert(b - x);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> m;
	dif.insert(0);
	dif.insert(sz(s));
	for (int i = 0; i < sz(s) - 1; ++i)
		if (s[i] != s[i + 1]) dif.insert(i + 1);  // initialize dif
	for (auto it = dif.begin(); next(it) != dif.end(); it++) {
		ret.insert(*next(it) - *it);  // initialize ret
	}
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;  // 1-indexed position
		modify(x - 1);
		modify(x);
		cout << *ret.rbegin() << " ";
	}
}
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

vector<vll> prefixSum2D(vector<vll>& a) {
    vector<vll> b(a.size(), vll(a[0].size()));
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

ll sumOfSquare(int x1, int y1, int x2, int y2, vector<vll>& a) {
    return (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1]) + a[x1 - 1][y1 - 1];
}

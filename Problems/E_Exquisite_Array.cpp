// E. Exquisite Array
// URL: https://codeforces.com/contest/2184/problem/E
// Time: 1/16/2026, 10:29:46 PM
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

struct DSU {
    vector<int> parent, size;
    int count; // of component

    DSU(int n) : parent(n + 1), size(n + 1, 1), count(n) { iota(all(parent), 0); }

    int find(int i) { return (parent[i] == i ? i : (parent[i] = find(parent[i]))); }

    bool same(int i, int j) { return find(i) == find(j); }

    int getSize(int i) { return size[find(i)]; }

    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1;
        else --count;
        if (size[i] > size[j]) swap(i, j);
        parent[i] = j;
        size[j] += size[i];
        return j;
    }
};

int calc(int n) {
    return n * (n - 1) / 2;
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    DSU dsu(n);
    vi ans(n, 0);

    vector<vector<int>> pos(n);
    for (int i = 0; i < n - 1; i++) {
        int diff = abs(a[i] - a[i + 1]);
        pos[diff].push_back(i);
    }

    for (int k = n - 1; k >= 1; k--) {
        if (dsu.count == 1) break;
        for (int idx : pos[k]){
            int sz1 = dsu.getSize(idx);
            int sz2 = dsu.getSize(idx + 1);
            dsu.merge(idx, idx + 1);
            ans[k] += calc(sz1 + sz2) - calc(sz1) - calc(sz2);
        }
    }

    for (int i = n - 2; i >= 0; i--){
        ans[i] += ans[i + 1];
    }
    
    for(int k = 1; k < n; k++)
        cout << ans[k] << " ";
    cout << "\n";
}

/*
given a permutation of size n
for each k from 1 to n - 1
find number of subarrays that each two consecutive elements has difference of at least k
example:
5 1 4 2 3
k = 1
5 1
1 4
4 2
2 3
5 1 4
1 4 2
4 2 3
5 1 4 2
1 4 2 3
5 1 4 2 3
10 = 4 + 3 + 2 + 1 = n (n - 1)/2

k = 2
5 1
1 4
4 2
5 1 4
1 4 2
5 1 4 2

okay so for each k
if a segment is valid for k
then it is also valid for all k' < k
the number of valid subarrays for the segment of lenght m is m (m - 1) / 2


going from right to left

5 1
5 1 4
1 4
5 1 4 2
4 2
1 4 2

each new valid number for a segment of size n adds n - 1 new subarrys to all k' <= k
I think a prefix sum approach would work here for caclulating the ans for each k

6 4 2 1 3 5

maybe use dsu to keep track of segments
as we add new elements we merge segments and calculate the number of new subarrays formed
but trying every k from 1 to n - 1 would be too slow

we can work on differences 
*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
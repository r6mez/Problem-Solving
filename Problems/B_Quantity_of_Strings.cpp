/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Quantity of Strings
// URL: https://codeforces.com/contest/150/problem/B
// Time: 6/30/2025, 7:24:49 PM
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

int pwmod(int a, int b, int m) {
    a %= m;
    int result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

void Ramez() {
    int n, m, k; cin >> n >> m >> k; 

    DSU ImNotFeelingOkay(n);

    for (int i = 0; i < n - k + 1; i++){
        for (int j = 0; j < k/2; j++){
            ImNotFeelingOkay.merge(i + j, i + k - 1 - j);
        }
    }

    int ItsGettingInMyHead = pwmod(m, ImNotFeelingOkay.count, MOD);

    cout << ItsGettingInMyHead;
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
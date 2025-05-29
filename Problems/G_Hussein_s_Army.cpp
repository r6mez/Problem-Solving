/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// G. Hussein's Army
// URL: https://codeforces.com/group/Rilx5irOux/contest/608858/problem/G
// Time: 5/29/2025, 4:12:50 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("army.in", "r", stdin); }
const int MOD = 1000000007;

int n, m, cnt, totalLength; 
map<int, int> idxs;

int sum(int n){
    return (n * (n + 1)) / 2;
}

int digit(int x){
    int l = 0, r = n + 1;
    
    while(l + 1 < r){
        int mid = (l + r)/2;
        if(sum(mid) < x) l = mid;
        else r = mid;
    }

    return r;
}

int getType(int pos) {
    auto it = idxs.find(pos);
    return (it != idxs.end()
            ? it->second
            : digit(pos));
};

void adjust(int p, int q, int delta){
    if (q >= 1 && q <= totalLength && getType(p) == getType(q)) {
        cnt += delta;
    }
};

void Ramez() {
    cin >> n >> m;
    cnt = sum(n) - n;
    totalLength = sum(n);

    while(m--){
        int x, y; cin >> x >> y;
        if (x == y) continue;

        for (auto p : {x, y}){
            for (auto dq : { -1LL, +1LL })
                adjust(p, p + dq, -1);

        }

        int tx = getType(x), ty = getType(y);
        idxs[x] = ty;
        idxs[y] = tx;

        for (auto p : {x, y})
            for (auto dq : { -1LL, +1LL })
                adjust(p, p + dq, +1);
    }

    cout << cnt << "\n";

    idxs.clear();
}

/*
NOTES:
0 + 1 + 2 + 3 = 6
12345678910
1223334444
4223334441
4232334441

*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}
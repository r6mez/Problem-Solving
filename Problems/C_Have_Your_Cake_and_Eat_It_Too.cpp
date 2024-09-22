// Ramez Medhat
// problem: C. Have Your Cake and Eat It Too
// URL: https://codeforces.com/contest/1983/problem/C  
// Start: 7/7/2024, 6:32:21 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()
#define search(vec, item) find(all(vec), item) != vec.end()
vector<vi> repGraph(int n, int m);
void dfs(int parent, vector<vi>& graph, vector<bool>& visited);
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i << ' ';
    return os;
}
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}

int n;
vi ans;


bool check(vll& a, vll& b, vll& c, ll target) {
    bool foundA = false;
    bool foundB = false;
    bool foundC = false;

    ll sumA = 0;
    ll lA = 0;
    ll rA = 0;
    for (rA = 0; rA < n; rA++) {
        sumA += a[rA];
        if (sumA >= target) { foundA = true; break; }
    }

    ll sumB = 0;
    ll lB = rA + 1;
    ll rB = rA + 1;
    for (rB = lB; rB < n; rB++) {
        sumB += b[rB];
        if (sumB >= target) { foundB = true; break; }
    }

    ll sumC = 0;
    ll lC = rB + 1;
    ll rC = rB + 1;
    for (rC = lC; rC < n; rC++) {
        sumC += c[rC];
        if (sumC >= target) { foundC = true; break; }
    }

    if (foundA && foundB && foundC) {
        rC = n-1;
        ans.push_back(lA + 1);
        ans.push_back(rA + 1);
        ans.push_back(lB + 1);
        ans.push_back(rB + 1);
        ans.push_back(lC + 1);
        ans.push_back(rC + 1);
        return true;
    }
    else return false;
}



void solve() {
    cin >> n;
    vll a(n), b(n), c(n); cin >> a >> b >> c;

    ll total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i];
    }

    ll target = ceil(total / 3.0);
    ans.clear();

    if (check(a, b, c, target)) {
        cout << ans[0] << " ";
        cout << ans[1] << " ";
        cout << ans[2] << " ";
        cout << ans[3] << " ";
        cout << ans[4] << " ";
        cout << ans[5] << " ";
    }
    else if (check(a, c, b, target)) {
        cout << ans[0] << " ";
        cout << ans[1] << " ";
        cout << ans[4] << " ";
        cout << ans[5] << " ";
        cout << ans[2] << " ";
        cout << ans[3] << " ";
    }
    else if (check(b, a, c, target)) {
        cout << ans[2] << " ";
        cout << ans[3] << " ";
        cout << ans[0] << " ";
        cout << ans[1] << " ";
        cout << ans[4] << " ";
        cout << ans[5] << " ";
    }
    else if (check(b, c, a, target)) {
        cout << ans[4] << " ";
        cout << ans[5] << " ";
        cout << ans[0] << " ";
        cout << ans[1] << " ";
        cout << ans[2] << " ";
        cout << ans[3] << " ";
    }
    else if (check(c, a, b, target)) {
        cout << ans[2] << " ";
        cout << ans[3] << " ";
        cout << ans[4] << " ";
        cout << ans[5] << " ";
        cout << ans[0] << " ";
        cout << ans[3] << " ";
    }
    else if (check(c, b, a, target)) {
        cout << ans[4] << " ";
        cout << ans[5] << " ";
        cout << ans[2] << " ";
        cout << ans[3] << " ";
        cout << ans[0] << " ";
        cout << ans[1] << " ";
    }
    else cout << "-1";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
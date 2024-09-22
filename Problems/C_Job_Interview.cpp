// ﷽
// problem: C. Job Interview
// URL: https://codeforces.com/contest/1976/problem/C  
// Start: 5/30/2024, 6:13:40 PM
#include <bits\stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()

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

//  brute force TLE
void solve() {
    ll n, m; cin >> n >> m;
    ll nm1 = n + m + 1;
    vector<pair<ll, ll>> people(nm1);
    for (int i = 0; i < nm1; i++) {
        cin >> people[i].first;
    }
    for (int i = 0; i < nm1; i++) {
        cin >> people[i].second;
    }

    for (int i = 0; i < nm1; i++) {
        ll sum = 0;
        ll p = 0, t = 0;
        for (int j = 0; j < nm1; j++)
        {
            if (i == j) continue;

            if (p < n && t < m) {
                if (people[j].first > people[j].second) {
                    sum += people[j].first;
                    p++;
                }
                else {
                    sum += people[j].second;
                    t++;
                }
            } else if (p < n) {
                sum += people[j].first;
                p++;
            } else if (t < m) {
                sum += people[j].second;
                t++;
            }
        }
        cout << sum << " ";
    } 
    cout << "\n";
}

/*
NOTES:
while looping on n+m+1;
if(p > t) ps += p;
else ts += t;

1 2
2 1 5 4
5 2 3 1

*/

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
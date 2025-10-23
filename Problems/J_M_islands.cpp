#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
    for (auto& i : v) os << i << ' '; return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    for (auto& i : v) is >> i; return is;
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector <pair<ll, ll>> directPaths(n);

    for (ll i = 0; i < n; i++) {
        cin >> directPaths[i].first;
        cin >> directPaths[i].second;
    }

    ll q;
    cin >> q;
    sort(directPaths.begin(), directPaths.end());

    // l, r
    // check if new l <= old r update r = v[i].second
    // else push to the vector
    // هيتبقى اخر واحد بوشيه برا اللوب

    vector <pair <ll, ll>> allPaths;

    ll l = directPaths[0].first;
    ll r = directPaths[0].second;


    for (ll i = 1; i < n; i++) {
        if (directPaths[i].first <= r) {
            r = max(directPaths[i].second, r);
        }
        else {
            allPaths.push_back({ l,r });
            l = directPaths[i].first;
            r = directPaths[i].second;
        }
    }

    allPaths.push_back({ l,r });

    sort(allPaths.begin(), allPaths.end());

    while (q--) {
        ll u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);

        auto it = upper_bound(allPaths.begin(), allPaths.end(), make_pair(u, LLONG_MAX));
        

        // cout << it->first << " " << it->second << endl;
        if (it == allPaths.begin()) {
            cout << "NO\n";
            continue;
        }

        it--;

        if (it->first <= u && it->second >= v) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}

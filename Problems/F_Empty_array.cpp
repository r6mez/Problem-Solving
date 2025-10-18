#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
    for (auto& i : v)
        os << i << ' ';
    return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    for (auto& i : v)
        is >> i;
    return is;
}
using ll = long long;
using ull = unsigned long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    vector <pair<ll, ll>> freq;
    for (ll i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());   //سورت هنا أهو
    for (ll i = 0; i < n; i++) {
        // cin >> v[i];
        bool flag = false;
        for (ll j = 0; j < freq.size(); j++) {
            if (freq[j].first == v[i]) {
                freq[j].second++;
                flag = true;
            }
        }
        if (flag == false) freq.push_back(make_pair(v[i], 1));
    }


    //sort(freq.begin(), freq.end());
    while (freq.size() > 0) {
        for (ll i = 0; i < freq.size(); i++) {
            if (freq[i].second > 0) {
                cout << freq[i].first << ' ';
                freq[i].second--;
            }
        }
        cout << endl;

        for (int i = 0; i < freq.size(); i++){
            if(freq[i].second == 0) freq.erase(freq.begin() + i);
        }
    }

    return 0;
}
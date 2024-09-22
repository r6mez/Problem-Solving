// ﷽
// problem: B. Symmetric Encoding
// URL: https://codeforces.com/contest/1974/problem/B  
// Start: 5/20/2024, 5:56:45 PM
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
    for(const auto& i : v) os << i << ' ';
    return os;
}
 
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for(auto& i : v) is >> i;
    return is;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> freq;
    string r;
    for (int i = 0; i < n; i++)
    {
        if(freq[s[i]] == 0){
            r.push_back(s[i]);
            freq[s[i]]++;
        }
    }
    sort(all(r));
    for (int i = 0; i < n; i++)
    {
        int index = r.find(s[i]);
        s[i] = r[r.size() - index - 1];
    }
    cout << s << "\n";
}

/*
NOTES:

*/

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
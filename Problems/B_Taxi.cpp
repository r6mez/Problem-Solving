// ﷽
// problem: B. Taxi
// URL: https://codeforces.com/problemset/problem/158/B  
// Start: 5/27/2024, 10:04:59 PM
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
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        m[num]++;
    }

    // Handling the Fours
    int cars = m[4];


    // Handling the 3+1
    cars += m[3];
    if(m[3] > m[1]){
        m[1] = 0;
    } else {
        m[1] -= m[3];
        m[3] = 0;
    }


    // Handling the 2+2
    cars += m[2]/2;
    m[2] = m[2]%2;

    
    // Handling the 2+1
    if(m[2]) {
        cars += 1;
        m[1] -= 2;
        if (m[1] == 1 || m[1] == 2) m[1] = 0;
    }


    // Handling the 1+1
    cars += ceil(m[1]/4.0);

    cout << cars << "\n";
}


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
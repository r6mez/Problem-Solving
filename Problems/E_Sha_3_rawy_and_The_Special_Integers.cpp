// ﷽
// problem: E - Sha3rawy and The Special Integers
// URL: https://vjudge.net/contest/630348#problem/E  
// Start: 5/23/2024, 5:43:50 PM
#include <iostream>
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
    for(const auto& i : v) os << i;
    return os;
}
 
int sumOfAll = 0;
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for(auto& i : v){
        is >> i;
        sumOfAll += i;
    }
    return is;
}

void solve(){
    int n; cin >> n;
    vi a(n); cin >> a;
    int sum = 0;
    int mid = round(sumOfAll/(double)n);
    for(auto num : a){
        sum += (pow((num - mid),2)); 
    }
    
    cout << sum;
}

/*
NOTES:
1
*/

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
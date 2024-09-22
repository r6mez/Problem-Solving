// ﷽
// problem: F. Books
// URL: https://codeforces.com/group/isP4JMZTix/contest/380008/problem/F  
// Start: 5/18/2024, 9:10:44 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int start = 0, end = 0;
    int current_time = 0;
    int max_books = 0;
    
    while(end < n) {
        current_time += a[end];
        
        while(current_time > t) {
            current_time -= a[start];
            start++;
        }
        
        max_books = max(max_books, end - start + 1);
        end++;
    }
    
    cout << max_books << endl;
}

/*
NOTES:
3 1 2 1
3 1
4 2 
3 2 
4 3 
 
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
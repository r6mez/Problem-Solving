// ﷽
// problem: H. Queries about less or equal elements
// URL: https://codeforces.com/group/isP4JMZTix/contest/379072/problem/H  
// Start: 5/8/2024, 6:04:23 PM
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

bool isValid(int arrayElement, int num){
    return (arrayElement <= num);
}

int searchForMaxIthatIsLessThanOrEqNum(int num, vi &a){
    int left = 0, right = a.size()-1;
    int i = 0;
    while(left <= right){
        int mid = (right+left)/2;
        if(isValid(a[mid], num)){
            left = mid+1;
        } else {
            right = mid-1;
        }
        i = left;
    }
    return i;
}

void solve(){
    int n,m; cin >> n >> m;
    vi a(n); for(int &i : a) cin >> i;
    sort(a.begin(), a.end());
    while (m--){
        int num; cin >> num;

        cout << searchForMaxIthatIsLessThanOrEqNum(num, a) << " ";

        // auto it = upper_bound(a.begin(), a.end(), num);
        // cout << distance(a.begin(), it) << " ";
    }
}

/*
1 3 5 7 9
num = 5
1 1 1 0 0 

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
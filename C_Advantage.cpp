// ﷽
// problem: C. Advantage
// URL: https://codeforces.com/problemset/problem/1760/C  
// Start: 5/11/2024, 6:41:50 PM
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

void solve(){
    int n; cin >> n;
    vi a(n); 
    multiset<int> s;

    for(int&i : a) {
        cin >> i;
        s.emplace(i);
    }

    auto end = s.end();
    end--;
    int maxV = *end;
    end--;
    int secMaxV = *end;

    for (int i = 0; i < n; i++)
    {
        if(a[i] != maxV) cout << a[i] - maxV << " ";
        else cout << a[i] - secMaxV << " ";
    }
    cout << "\n";
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
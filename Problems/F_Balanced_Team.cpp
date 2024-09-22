// ﷽
// problem: F. Balanced Team
// URL: https://codeforces.com/group/isP4JMZTix/contest/379072/problem/F  
// Start: 5/8/2024, 8:19:55 PM
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
    vi skills(n); for(int &i : skills) cin >> i;
    sort(skills.begin(), skills.end());

    int maxAnswer = 0;
    for (int i = 0; i < n; i++)
    {
        int left = i, right = n-1, answer = i;
        while(left <= right) {
            int mid = (left+right)/2;
            if(skills[mid] - skills[i] <= 5){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            answer = right;   
        }
        maxAnswer = max(maxAnswer, answer-i+1);
    }
    
    cout << maxAnswer << "\n";
}

/*
NOTES:
1 10 17 12 15 2
1 2 10 12 15 17

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
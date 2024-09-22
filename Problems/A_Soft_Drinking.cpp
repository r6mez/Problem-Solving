// ﷽
// problem: A. Soft Drinking
// URL: https://codeforces.com/problemset/problem/151/A  
// Start: 5/6/2024, 6:19:51 PM
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
    int friends, bottels, bottelsDrinkAmount, limes, limeSlices, salt; 
    cin >> friends >> bottels >> bottelsDrinkAmount >>  limes >> limeSlices >> salt;
    int neededDrinkPerFreind, neededSaltPerFriend;
    cin >> neededDrinkPerFreind >> neededSaltPerFriend; 

    int drinkPerFriend = (bottels*bottelsDrinkAmount)/(neededDrinkPerFreind*friends);
    int limesPerFriend = (limes*limeSlices)/(friends);
    int saltPerFriend = (salt)/(neededSaltPerFriend*friends);
    cout << min({drinkPerFriend, limesPerFriend, saltPerFriend});
}

/*
NOTES:

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
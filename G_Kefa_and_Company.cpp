// ﷽
// problem: G. Kefa and Company
// URL: https://codeforces.com/group/isP4JMZTix/contest/380008/problem/G  
// Start: 5/20/2024, 1:20:57 PM
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
    ll n, maxValidDifference;
    cin >> n >> maxValidDifference;
    vector<pair<ll,ll>> friends(n); 


    for (ll i = 0; i < n; i++)
    {
        ll money, friendship; cin >> money >> friendship;
        friends[i] = make_pair(money, friendship);
    }
    sort(all(friends));
    

    ll i = 0, j = 0;
    ll friendshipSum = 0;
    ll maxFriendshipSum = 0;
    
    while(j < n){
        ll difference = friends[j].first - friends[i].first;
        if(difference < maxValidDifference){
            friendshipSum += friends[j++].second;
        } else {
            friendshipSum -= friends[i++].second;
        }
        maxFriendshipSum = max(friendshipSum, maxFriendshipSum);   
    }
    
    cout << maxFriendshipSum;
}

/*
NOTES:
n friends 
d maxValidDifference between any to friends in the company
we want to maximize total friendship of all the people we select

4 5 

0 100 <- 
75 1
75 5
150 20

5 100

0 7
11 32
46 8
87 54
99 10 --take all--

10 10
0 10 
3 10 
4 10
11 10
15 10
26 10 <-
27 10 <-
28 10 <-
29 10 <-
40 10



10 10
0 10 
3 10 
4 10
11 10
15 10
26 10 <-
27 10 <-
28 10 <-
29 10 <-
40 10


6 10
0 10 
3 5
4 10  <
11 10 <
14 10 < 
15 10



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
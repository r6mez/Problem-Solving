// ﷽
// problem: T. Mikasa and Love
// URL: https://codeforces.com/group/y3RUgysowo/contest/376178/problem/T  
// Start: 4/10/2024, 5:43:11 PM
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define loop (n) for (int i = 0; i < (n); i++)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    ll stones[n]; ll sum = 0, maxSum = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> stones[i];
        if(stones[i] > sum + stones[i]) sum = stones[i]; // restarting the sum when it finds a new variable bigger than the total sum.
        else sum += stones[i]; 

        if(maxSum < sum) maxSum = sum;  // keeps track of the biggest sum
    }
    if((maxSum)%2 == 0) cout << "Mikasa";
    else cout << "Ereh";
    return 0;
}
 

/* 
0  -1111
   -2  9  -10  10  -20
0  -2  7  -3   7   -13  
*/
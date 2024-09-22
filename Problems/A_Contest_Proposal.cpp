// ﷽
// problem: A. Contest Proposal
// URL: https://codeforces.com/contest/1972/problem/A  
// Start: 4/30/2024, 5:36:25 AM
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
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>

void solve(){
    int n; cin >> n;
    multiset<ll> proposed, expexted;
    
    for (int i = 0; i < n; i++)
    {
        int problem; cin >> problem;
        proposed.emplace(problem);
    }
    for (int i = 0; i < n; i++)
    {
        int problem; cin >> problem;
        expexted.emplace(problem);
    }

    int counter = 0;
    auto j = expexted.begin();
    for (auto i = proposed.begin(); i != proposed.end(); i++)
    {
        if(*i > *j) {
            i = proposed.emplace(*j);
            proposed.erase(--(proposed.end()));
            counter++;
        }
        j++;
    }

    cout << counter << "\n";    
}

/*
NOTES:
n problems 
a1 a2 a3 propesed problems diff
b1 b2 b3 expected diffeculty 

you choose an integer w
insert it into the array a
sort array a in non-decreasing order, and remove the last element from it.

minimum number of new problems to make ai ≤ bi  for all i


1 2 4 5 6 7 8
1 2 3 4 5 6
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
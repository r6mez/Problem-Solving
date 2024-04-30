// ﷽
// problem: G. Queue
// URL: https://codeforces.com/group/isP4JMZTix/contest/392597/problem/G  
// Start: 4/29/2024, 11:37:51 AM
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
    queue<int> in; 
    map<int,int> freq;

    for (int i = 0; i < n; i++){
        int car; cin >> car; in.push(car);
    }

    int overcome = 0;
    for (int i = 0; i < n; i++){
        int car; cin >> car; 
        while(freq[in.front()]) in.pop();

        if(in.front() != car) overcome++;   
        else in.pop();

        freq[car]++;
    }
    
    cout << overcome;
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

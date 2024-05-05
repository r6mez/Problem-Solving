// ﷽
// problem: A. Juicer
// URL: https://codeforces.com/problemset/problem/709/A  
// Start: 5/5/2024, 8:05:06 PM
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
    int oranges, maxSize, wasteCapacity;
    cin >> oranges >> maxSize >> wasteCapacity;

    int waste = 0, counter = 0;
    while(oranges--){
        int orangeSize; cin >> orangeSize;
        if(orangeSize > maxSize) continue;
        waste += orangeSize;
        if(waste > wasteCapacity) {
            waste = 0;
            counter++;
        }
    }
    cout << counter;
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
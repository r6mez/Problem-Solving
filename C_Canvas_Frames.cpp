// ﷽
// problem: C. Canvas Frames
// URL: https://codeforces.com/group/isP4JMZTix/contest/380288/problem/C  
// Start: 4/23/2024, 6:51:20 PM
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
    int n; cin >> n;
    int a[101] = {0};
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }

    int numberOfTwos = 0;
    for(int i : a){
        numberOfTwos += (i/2);
    }

    cout << (numberOfTwos / 2);
    return 0;
}
// ﷽
// problem: M. Inna and New Matrix of Candies
// URL: https://codeforces.com/group/isP4JMZTix/contest/380288/problem/M  
// Start: 4/24/2024, 8:18:49 PM
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
    int n,m; cin >> n >> m;
    map<int,int> distances;
    while (n--){
        string s; cin >> s;
        int gIndex = s.find('G'), sIndex = s.find('S');
        if(gIndex > sIndex) return cout << -1, 0;
        distances[sIndex-gIndex]++;
    }
    cout << distances.size();
    return 0;
}
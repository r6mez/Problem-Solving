// ﷽
// problem: A. Vector
// URL: https://codeforces.com/group/isP4JMZTix/contest/392597/problem/A  
// Start: 4/29/2024, 10:33:10 AM
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

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    cin >> t;

    vi seq;
    for (int i = 0; seq.size() < 1001; i++)
    {
        if(i%3 != 0 && i%10 != 3) seq.push_back(i);
    }
    
    while (t--){
        int i; cin >> i; cout << seq[i-1] << "\n";
    }
    return 0;
}
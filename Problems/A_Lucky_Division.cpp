// ﷽
// problem: A. Lucky Division
// URL: https://codeforces.com/problemset/problem/122/A  
// Start: 4/13/2024, 9:44:30 PM
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


bool isLucky(int n){
    while (n != 0)
    {
        int digit = n % 10;
        n /= 10;
        if(!(digit == 7 || digit == 4)) return false;
    }
    return true;
}

bool isDividableByLucky(int n){
    if(isLucky(n)) return true; 

    for (int i = 1; i <= n/2; i++)
    {
        if(!isLucky(i)) continue;
        else {
            if (n%i == 0) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    if(isDividableByLucky(n)) cout << "YES";
    else cout << "NO";
    return 0;
}

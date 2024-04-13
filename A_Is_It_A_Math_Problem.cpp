// ﷽
// problem: A. Is It A Math Problem?
// URL: https://codeforces.com/gym/104447/problem/A  
// Start: 4/13/2024, 10:46:18 PM
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

ll numberOfDivisors(ll n){
    ll counter = 0;
     for (ll i = 1; i <= sqrt(n); i++)
    {
        if(n%i==0){
            counter++;
            if(n/i != i) counter++;
        }
    }
    return counter;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    ll x = numberOfDivisors(n);
    if(x%2 == 0){
        cout << n << " " << x/2;
    } else {
        ll temp = pow(n,0.5);
        cout << temp << " " << x;
    }
    return 0;
}

/*
10
1 2 5 10


16
1 2 4 8 16
5/2

4 5

18
1 2 3 6 9 18

25
1 5 25

*/
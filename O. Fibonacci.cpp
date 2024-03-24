#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int fibonacciAtN(int n){
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return fibonacciAtN(n-1) + fibonacciAtN(n-2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    cout << fibonacciAtN(n-1);
    return 0;
}

// 1 2 3 5 8 13
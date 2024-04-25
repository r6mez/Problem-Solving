// ﷽
// problem: B. Vlad and Shapes
// URL: https://codeforces.com/contest/1926/problem/B  
// Start: 4/25/2024, 8:22:12 PM
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
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        bool isTrinagle = false;
        bool isChecked = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(a[i][j] == '1'){
                    for (int k = 0; (i+k < n && j+k < n); k++)
                    {   
                        if (a[i+k][j] != a[i][j+k]){
                            isTrinagle = true;
                            break;
                        }
                    }
                    isChecked = true;
                    break;
                }
            }
            if(isChecked) break;
        }
        
        if(isTrinagle) cout << "TRIANGLE\n";
        else cout << "SQUARE\n";
    }
    return 0;
}

/*
00000
01110
00100
00000

000000000010
000000000111
000000000000
000000000000
000000000000
000000000000



*/
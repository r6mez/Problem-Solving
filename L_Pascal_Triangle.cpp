#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> pascalTringal(n, vector<int>(n,0));
    pascalTringal[0][0] = 1;
    cout << pascalTringal[0][0] << "\n";
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(j!=0) pascalTringal[i][j] = pascalTringal[i-1][j-1] + pascalTringal[i-1][j];
            else pascalTringal[i][j] = pascalTringal[i-1][j];
            if(pascalTringal[i][j]) cout << pascalTringal[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

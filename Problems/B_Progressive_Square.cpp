#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--){
        int n,c,d; cin >> n >> c >> d;
    
        vi a(n*n);
        for (int i = 0; i < n*n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());


        vector<vector<int>> mat(n,vector<int>(n));
        mat[0][0] = a[0];
        vi myA(n*n);
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i != n-1) mat[i+1][j] = mat[i][j] + c;
                if(j != n-1) mat[i][j+1] = mat[i][j] + d;
                myA[k] = mat[i][j];
                k++;
            } 
        }

        sort(myA.begin(), myA.end()); 

        bool isPS = true;
        for (int i = 0; i < n*n; i++)
        {
            if(myA[i] != a[i]){
                isPS = false;
                break;
            } 
        }
        
        if(isPS) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int Ra, Ca; cin >> Ra >> Ca;
    int A[Ra][Ca];
    for (int i = 0; i < Ra; i++)
    {
        for (int j = 0; j < Ca; j++)
        {
            cin >> A[i][j];
        }
    }
    
    int Rb, Cb; cin >> Rb >> Cb;
    int B[Rb][Cb];
    for (int i = 0; i < Rb; i++)
    {
        for (int j = 0; j < Cb; j++)
        {
            cin >> B[i][j];
        }
    }

    int C[Ra][Cb];
    for (int i = 0; i < Ra; i++)
    {
        for (int j = 0; j < Cb; j++)
        {   
            C[i][j] = 0;
            for (int x = 0; x < Ca; x++)
            {
                C[i][j] += A[i][x]*B[x][j]; 
            }       
        }
    }

    for (int i = 0; i < Ra; i++)
    {
        for (int j = 0; j < Cb; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

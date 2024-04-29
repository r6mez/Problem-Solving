// ﷽
// problem: E. Games
// URL: https://codeforces.com/group/isP4JMZTix/contest/380288/problem/E  
// Start: 4/23/2024, 10:51:06 PM
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
    int num;
    cin >> num;
    int h[num], g[num];
    int host, guest = 0;
    for (int i = 0; i < num; i++) {
        cin >> host >> guest;
        h[i] = host;
        g[i] = guest;
    }
    int hfreq[105] = {0};
    int gfreq[105] = {0};
    for (int i = 0; i < num; i++) {
        hfreq[h[i]]++;
        gfreq[g[i]]++;
    }

    int sum = 0;
    for (int i = 0; i < 105; i++)
    {
        sum += hfreq[i] * gfreq[i];
    }
    
    cout<<sum;
}

/*
4
1 2
2 4
3 4
3 2
      0 1 2 3 4 
hFreq 0 1 1 2 0
gFreq 0 0 2 0 2
*/

// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     int n; cin >> n;
//     vector<pair<int,int>> a(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i].first >> a[i].second;
//     }

//     int counter = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {   
//             if(i == j) continue;
//             if(a[i].first == a[j].second) counter++;
//         }
//     }

//     cout << counter;
//     return 0;
// }



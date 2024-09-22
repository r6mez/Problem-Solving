// ﷽
// problem: B. Make It Ugly
// URL: https://codeforces.com/contest/1954/problem/B  
// Start: 4/12/2024, 5:24:03 PM
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
        vi a(n); 
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int counter = 0, answer = n;
        for (int i = n-1; i >= 0; i--)
        {
            if(a[i] != a[0]){
                answer = min(answer,counter);
                counter = 0;
            } else {
                counter++;
            }
        }
        
        answer = min(answer,counter);

        if(answer == n) cout << -1 << "\n";
        else cout << answer << "\n";
    }
    return 0;
}


// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     int t; cin >> t;
//     while (t--){
//         int n; cin >> n;
//         vi a(n); 
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }
//         int lengthRight = 0, lengthLeft = 0;
//         bool isfound = false;
//         for (int i = 0; i < n; i++)
//         {
//             if(a[i] == a[n-1]) lengthRight++;
//             else {
//                 isfound = true;
//                 break;
//             }
//         }
//         for (int i =n-1; i >= 0; i--)
//         {
//             if(a[i] == a[0]) lengthLeft++;
//             else {
//                 isfound = true;
//                 break;
//             }
//         }

//         int lengthMiddle = INT_MAX;
//         bool isFoundInMiddle = false;
//         for (int i = 1; i < n-1; i++)
//         {   
//             if(a[i-1] == a[i+1] && a[i] != a[i-1] && a[i] == a[0]) {   
//                 if(isFoundInMiddle == false){
//                     lengthMiddle = 1;
//                     isFoundInMiddle = true;
//                     isfound = true;
//                 } else{
//                     lengthMiddle++;
//                 }
//             }
//         }
//         if(isfound) cout << min(min(lengthLeft, lengthRight), lengthMiddle) << "\n";
//         else cout << "-1\n";
//     }
//     return 0;
// }


/*

1 1 1 2 1 2 1 1 1 
1 1 1 2 2 1 1 1 

1 1 1 2 2 1 2 1 1 1 
*/
// ﷽
// problem: A. Card Exchange
// URL: https://codeforces.com/contest/1966/problem/0  
// Start: 4/27/2024, 5:35:02 AM
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

void solve(){
    int n,k; cin >> n >> k;
    map<int, int> freq;
    bool theresK = false;
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num; 
        freq[num]++;
        if(freq[num] >= k) theresK = true;
    }

    if (theresK) {
        cout << k-1 << "\n";
    } else {
        cout << n << "\n";
    }
}

/*
NOTES:

41144
1111
111
11

6 2 
10 10 20 20 30 40
20 20 20 30 40
20 20 30 40
40 40
40

6 2 
10 10 10 20 30 40
10 10 20 30 40
20 20 30 40
30 30 40
40 40
40

6 2 
10 20 30 40 50 60
*/

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}



// void solve(){
//     int n,k; cin >> n >> k;
//     map<int, int> freq;
//     for (int i = 0; i < n; i++)
//     {
//         int num; cin >> num; 
//         freq[num]++;
//     }

//     if(freq.size() == 1 || k > n) {
//         cout << 1 << "\n"; return;
//     }

//     bool theresK = true;
//     while (theresK)
//     {
//         bool kFound = false;
//         for(auto element : freq){
//             if(element.second > k){
//                 element.second = k;
//                 kFound = true;
//             } else if (element.second == k){
//                 element.second = 0;
//                 for(auto anotherElement : freq){
//                     if(anotherElement.second > 0) {
//                         anotherElement.second += k-1;
//                         break;
//                     }
//                 }
//                 kFound = true;
//             }
//         }
//         if(kFound == false) theresK = false;
//     }
    
//     int size = 0;
//     for(auto element : freq){
//         size += element.second;
//     }
//     cout << size << "\n";
// }
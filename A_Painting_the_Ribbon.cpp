// ﷽
// problem: A. Painting the Ribbon
// URL: https://codeforces.com/contest/1954/problem/0  
// Start: 4/12/2024, 4:35:59 PM
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
#include <algorithm>

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
        int n, m, k; cin >> n >> m >> k;

        int similarParts = ceil(((double)n)/m);
        if(m > n) similarParts = 1;
        int requireChangeParts = n - similarParts;
        
        if(k < requireChangeParts) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*

Color formation
5 1 (1 1 1 1 1) ceil(5/1.0) = 5 ...5%4 = 0 
5 2 (1 1 1 2 2) ceil(5/2.0) = 3 ...5%2 = 1
5 3 (1 1 2 2 3) ceil(5/3.0) = 2 ...5%2 = 1
5 4 (1 1 2 3 4) ceil(5/4.0) = 1 ...5%4 = 1
5 5 (1 2 3 4 5) ceil(5/5.0) = 1 ...5%5 = 0
all n-1 colors are repeated ceil(n/m) times 
the nth color are repeated n%m times


n m k
1 1 1 false 
5 1 1 false 
5 2 1 true
5 2 2 false 
5 5 3 true 

(n > m)
(m == n)
SimilarParts = n%m || round(((double)n)/m)
(m > n)
SimilarPart = 1;

k >= n - (n % m)

3 10 3 (1 2 3) SimilarParts = 1 (3<1 false) NO
3 10 2 (1 2 3) SimilarParts = 1 (2<1 false) NO
3 10 1 (1 2 3) SimilarParts = 1 (1<1 true) YES
5 1 1 (1 1 1 1 1) similarParts = 5 ... rcp = 0 (1 < 0 false) NO


5 4 3 NO
(1 2 3 4 1) round(5/4.0) = 1

*/

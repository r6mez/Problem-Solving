// ﷽
// problem: A. Filling Shapes
// URL: https://codeforces.com/problemset/problem/1182/A  
// Start: 4/14/2024, 3:40:13 PM
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
    int n; cin >> n;
    int area = n*3;
    if(area % 6 == 0){
        int numberOfRectangles = area/6;
        ll numberOfWays = pow(2,numberOfRectangles);
        cout << numberOfWays;
    } else {
        cout << 0;
    }
    return 0;
}

/* 
every rectangle of size 2*3 has two 2 to fill it 

number of Squares = area/(2*3) = area/6

Ways of One Rectangles:
1
2

Ways of Two Rectangles: 
1 1
1 2
2 1
2 2

Ways of Three Rectangles:
1 1 1
1 1 2
1 2 1 
1 2 2
2 1 1
2 1 2
2 2 1
2 2 2

numberOfWays = pow(2,numberOfRectangles);
*/
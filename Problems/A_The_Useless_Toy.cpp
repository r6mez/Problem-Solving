// ﷽
// problem: A. The Useless Toy
// URL: https://codeforces.com/problemset/problem/834/A  
// Start: 4/11/2024, 2:24:37 PM
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

int getPostitionNumber(char position){
    switch (position)
    {
        case 'v':
            return 0;
            break;
        case '<':
            return 1;
            break;
        case '^':
            return 2;
            break;
        case '>':
            return 3;
            break;
        default:
            return -1;
            break;
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    char start, end; cin >> start >> end;
    int seconeds; cin >> seconeds;

    seconeds %= 4;
    int startNum = getPostitionNumber(start), endNum = getPostitionNumber(end);
    int cw = (startNum+seconeds)%4;
    int ccw = ((startNum-seconeds)%4 + 4)%4;

    if (endNum == cw && endNum == ccw) cout << "undefined";
    else if(endNum == cw) cout << "cw";
    else if (endNum == ccw) cout << "ccw";
    return 0;
}

/*
v 0
< 1
^ 2
> 3


*/
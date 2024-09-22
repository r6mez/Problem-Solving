#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    string s; ll n;
    cin >> s >> n;
    ll temp = 0;
    for (int i = 0; i < s.size(); i++)
    {
        temp *= 10;
        temp += s[i] - '0';
        temp %= n;
    } 

    if(temp == 0) cout << "YES";
    else cout << "NO";
    return 0;
}
// 123 6
// (((((1%6)*10 + 2)%6)*10 + 3)%6)*10 = 30 
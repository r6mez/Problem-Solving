// ﷽
// problem: N. Sticky Spelling Situation
// URL: https://codeforces.com/group/isP4JMZTix/contest/380288/problem/N  
// Start: 4/24/2024, 9:36:48 PM
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
    string s1, s2; cin >> s1 >> s2;
    int a1[200] = {0}, a2[200] = {0};
    for (int i = 0; i < n; i++)
    {
        a1[s1[i]]++;
        a2[s2[i]]++;
    }

    int count = 0;
    for (int i = 'a'; i <= 'z'; i++)
    {
        if(a1[i] != a2[i]) count += abs(a1[i] - a2[i]); 
    }
    
    cout << count/2;
    
    return 0;
}

/*
abced 
abcdf
111010 
111101
*/
// ﷽
// problem: B. Garland
// URL: https://codeforces.com/group/isP4JMZTix/contest/380288/problem/B  
// Start: 4/22/2024, 11:18:49 PM
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
    string have, want; cin >> have >> want;
    int haveFreq[123] = {0}, wantFreq[123] = {0};
    
    for(char c : have) haveFreq[c]++;
    for(char c : want) wantFreq[c]++;
    
    int sum = 0;
    for (int i = 97; i < 123; i++)
    {   
        if(wantFreq[i] != 0 && haveFreq[i] == 0) {
            sum = -1;
            break;
        }
        if(haveFreq[i] >= wantFreq[i]){
            sum += wantFreq[i];
        } else {
            sum += haveFreq[i];
        }
    }
    
    if(sum == 0) cout << -1;
    else cout << sum;
    return 0;
}

/*
have
want

freq of what you have and what you want
loop for each char
if (what you have >= what i need) sum += what i need
else sum += have;

if (sum == 0) cout << -1
else cout << 1;

*/
// ﷽
// problem: A. Carrot Cakes
// URL: https://codeforces.com/contest/799/problem/A  
// Start: 4/23/2024, 4:14:11 PM
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
    int neededCakes,ovenBakingTime,ovenCapacity,timeToBuildSecondOven;
    cin >> neededCakes >> ovenBakingTime >> ovenCapacity >> timeToBuildSecondOven;

    int lastStepBeforeFisish = ((neededCakes - 1) / ovenCapacity) * ovenBakingTime;
    if(lastStepBeforeFisish > timeToBuildSecondOven) cout << "YES";
    else cout << "NO";

    return 0;
}

/*
8 6 4 5
(7 / 4) * 6 = 1 * 6 = 6 > 5 
(7 / 4) * 6 = 1 * 6 = 6 = 6
(9 / 11) * 3 = 0 * 3 = 0 < 6
(3 / 1) * 2 = 3 * 2 = 6 > 4

*/
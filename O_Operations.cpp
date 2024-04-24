// ﷽
// problem: O. Operations
// URL: https://codeforces.com/group/isP4JMZTix/contest/380288/problem/O  
// Start: 4/24/2024, 9:43:47 PM
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
    double p; cin >> p;
    while (p--){
        double a, b; cin >> a >> b;
        map<double, int> answers;
        answers[a+b]; 
        answers[b+a]; 
        answers[a-b]; 
        answers[b-a]; 
        answers[a*b]; 
        answers[b*a]; 
        answers[a/b]; 
        answers[b/a]; 
        cout << answers.size() << "\n";
    }    
    return 0;
}

/*
2 2
2+2 = 4 
2-2 = 0
2+2 = 4
2-2 = 4
2-2 = 4
2*2 = 4
2/2 = 1
2/2 = 1

-> 3


*/
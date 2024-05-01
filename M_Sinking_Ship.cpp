// ﷽
// problem: M. Sinking Ship
// URL: https://codeforces.com/group/isP4JMZTix/contest/392597/problem/M  
// Start: 5/1/2024, 4:59:52 AM
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

int getStatusNumber(string status){
    if(status == "rat") return 4;
    else if(status == "woman") return 3;
    else if(status == "child") return 3;
    else if(status == "man") return 2;
    else if(status == "captain") return 1;
    else return 5;
}

void solve(){
    int n; cin >> n;
    priority_queue<tuple<int,int,string>> q;
    for (int i = n; i > 0; i--)
    {
        string name, status; cin >> name >> status;
        int statusNum = getStatusNumber(status);
        q.emplace(make_tuple(statusNum, i, name));
    }  
    while(!q.empty()){
        cout << get<2>(q.top()) << "\n";
        q.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
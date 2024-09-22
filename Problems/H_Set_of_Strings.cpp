// ﷽
// problem: H. Set of Strings
// URL: https://codeforces.com/group/isP4JMZTix/contest/380288/problem/H  
// Start: 4/24/2024, 5:50:06 PM
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
    int k; cin >> k;
    string q; cin >> q;
    if(k == 1) {
        cout << "YES\n" << q;
        return 0;
    }

    int freq[200] = {0};
    int numberOfSubStrings = 0;
    vector<string> subStrings;
    int start = 0;
    for(int i = 0; i < q.size(); i++){
        if(freq[q[i]] == 0){
            numberOfSubStrings++;
            freq[q[i]]++;
            if(i != 0){
                subStrings.push_back(q.substr(start, (i)-start));
                start = i;
            }
        }
        if(numberOfSubStrings == k){
            subStrings.push_back(q.substr(start, (q.length())-start));
            break;
        }
    }
    
    if(numberOfSubStrings == k){
        cout << "YES\n";
        for(string s : subStrings) cout << s << "\n";
    } else {
        cout << "NO";
    }
    
    return 0;
}

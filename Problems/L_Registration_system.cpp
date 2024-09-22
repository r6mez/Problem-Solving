// ﷽
// problem: L. Registration system
// URL: https://codeforces.com/group/isP4JMZTix/contest/380288/problem/L  
// Start: 4/24/2024, 7:46:20 PM
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    map<string, int> names;
    while (n--){
        string s; cin >> s;
        if(names[s] == 0){
            cout << "OK\n";
        } else {
            string newName = s + to_string(names[s]);
            cout << newName << "\n";
        }
        names[s]++;
    }
    return 0;
}

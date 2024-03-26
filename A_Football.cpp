#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    char team = s[0];
    int counter = 0;
    bool isDangrous = false;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == team) {
            counter++;
            if(counter == 7) {
                isDangrous = true;
                break;
            }
        }
        else {
            team = s[i];
            counter = 1;
        }
    }
    
    cout << (isDangrous? "YES" : "NO");
    return 0;
}
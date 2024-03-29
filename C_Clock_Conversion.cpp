#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

string format(int n){
    if(n<10) return "0" + to_string(n);
    else return to_string(n);
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int hours, minutes;
        char colons;
        cin >> hours >> colons >> minutes;
        if(hours > 12) {
            cout << format(hours-12) << colons << format(minutes) << " PM\n";
        } else if(hours == 0){
            cout << "12" << colons << format(minutes) << " AM\n";
        } else if(hours == 12){
            cout << "12" << colons << format(minutes) << " PM\n";
        }else {
            cout << format(hours) << colons << format(minutes) << " AM\n";
        }
    }
    return 0;
}

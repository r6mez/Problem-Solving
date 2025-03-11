#include <bits/stdc++.h>
using namespace std;
#define ll long long

int start, ending;
ll ways = 0;

void calc(int current = start){
    if(current == ending) {
        ways++;
        return;
    } else if (current > ending) {
        return;
    }
    calc(current+1);
    calc(current+2);
    calc(current+3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> start >> ending;
    calc();
    cout << ways;
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        ll n, k, s = 0;
        cin >> n >> k;
        vll ships(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ships[i];
            s += ships[i];
        }

        if(k >= s){
            cout << n << endl;
            continue;
        }

        ll shipsSunk = 0;
        ll front = 0;
        ll back = n-1;
        while (k && (front < back)) {
            int mini = min(ships[front], ships[back]);

            
            if (k >= mini*2) {
                shipsSunk++;
                k -= mini*2;
                if (ships[front] < ships[back]) {
                    ships[back] -= ships[front];
                    front++;
                } 
                else if (ships[front] == ships[back]) {
                    front++;
                    back--;
                    shipsSunk++;
                }
                else {
                    ships[front] -= ships[back];
                    back--;
                } 
            } else if ((k+1) == (mini*2) && ships[front] <= ships[back]){
                shipsSunk++;
                break;
            }
            else {
                break;
            }
        }
        cout << shipsSunk << "\n";
    }
    return 0;
}

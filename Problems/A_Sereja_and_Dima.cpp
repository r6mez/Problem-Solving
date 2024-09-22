#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int s = 0,d = 0;
    bool isSTurn = true;
    int i = 0, j = n-1;
    while (i <= j)
    {
        int max;
        if(a[i] > a[j]){
            max = a[i];
            i++;
        } else {
            max = a[j];
            j--;
        }
        if(isSTurn) s += max;
        else d += max;
        isSTurn = !isSTurn;
    } 
    cout << s << " " << d;
    return 0;
}

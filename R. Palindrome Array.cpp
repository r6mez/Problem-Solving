#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

bool isPalindrome(ll a[], int n, int i = 0){
    if(a[i] != a[n-i-1]) return false;
    if(i == n/2) return true;
    else return isPalindrome(a, n, i+1);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << (isPalindrome(a,n)? "YES" : "NO");
    return 0;
}

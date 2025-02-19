/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// I. Using vector
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/I
// Time: 2/17/2025, 11:16:25 PM
#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define FAST std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
int main()
{
    FAST
    long long n, q;cin >> n >> q;
    vll v(n); cin >> v; // 2 4 9 5 3 4 7 2
    string s;long long l, r;
    while (q--)
    {
        cin >> s;
        if (s == "sort")
        {
            cin >> l >> r; //1- 5 8
            l--;r--;
            if(l > r) swap(l, r);
            sort(v.begin() + l, v.begin() + r + 1); // 2 4 5 9 2 3 4 7 

        }
        else if (s == "front") // 5- 
        {
            cout << v.front() << endl; // 3 
        }
        else if (s == "back")// 3
        {
            cout << v.back() << endl; 
        }
        else if (s == "reverse")
        {
            cin >> l >> r; l--;r--;
            if(l > r) swap(l, r);
            reverse(v.begin() + l, v.begin() + r + 1); 
        }
        else if (s == "pop_back")
        {
            v.pop_back(); 
        }
        else if (s == "push_back")
        {
            cin >> l; l--;
            v.push_back(l); 
        }
        else if (s == "print") 
        {
            cin >> l; l--;
            cout << v[l] << endl;
        }

    }

    return 0;
}


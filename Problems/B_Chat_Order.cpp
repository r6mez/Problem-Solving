    // ﷽
    // problem: B. Chat Order
    // URL: https://codeforces.com/problemset/problem/637/B  
    // Start: 4/11/2024, 3:34:28 PM
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
        int n; cin >> n;
        vector<string> order(n);
        map<string, bool> messages;

        for (int i = 0; i < n; i++)
        {
            cin >> order[i];
            messages[order[i]] = 0;
        }

        for (int i = n-1; i >= 0; i--)
        {
            if(messages[order[i]] == false){
                messages[order[i]] = true;
                cout << order[i] << " \n";
            }
        }
        return 0;
    }

/*
when it searchs
searchs based on the < operator (time) and checks equality with the == operator (name)
so it never finds the appropraite message.
*/
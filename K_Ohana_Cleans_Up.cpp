// ﷽
// problem: K. Ohana Cleans Up
// URL: https://codeforces.com/group/isP4JMZTix/contest/380288/problem/K  
// Start: 4/24/2024, 6:32:46 PM
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    map<string, int> FreqOfStrings;
    int maxFreq = 0;
    while(n--){
        string s; cin >> s;
        FreqOfStrings[s]++;
        maxFreq = max(maxFreq, FreqOfStrings[s]);
    }
    cout << maxFreq;
    return 0;
}

/*
Old Long Solution

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    if(n == 1){
        cout << 1; return 0;
    }
    char a[n][n];
    vector<vector<int>> cleanable(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == '0') cleanable[i].push_back(j);
        }
    }
    
    int columns = 0;
    int maxResult = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if(cleanable[i] == cleanable[j]) columns++;
        }
        maxResult = max(maxResult,columns);
        columns = 0;
    }

    cout << (maxResult);
    return 0;
}
*/

/*
It can only sweep the whole column.
sweep the clean becomes dirty, and the dirty becomes clean
1 clean 0 dirty
Wants maximum possible number of rows that are completely clean. 

0101 0   2
1000   1 2 3
1000   1 2 3
0101 0   2 

2131


10
0100000000 0   2 3 4 5 6 7 8 9  
0000000000 0 1 2 3 4 5 6 7 8 9
0100000000 0   2 3 4 5 6 7 8 9
0000000000 0 1 2 3 4 5 6 7 8 9
0100000000 0   2 3 4 5 6 7 8 9
0000000000 0 1 2 3 4 5 6 7 8 9
0100000000 0   2 3 4 5 6 7 8 9
0000000000 0 1 2 3 4 5 6 7 8 9
0100000000 0   2 3 4 5 6 7 8 9
0100000000 0   2 3 4 5 6 7 8 9
*/
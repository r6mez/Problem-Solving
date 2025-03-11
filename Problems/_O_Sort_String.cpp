#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    cin >> s;
    sort(s.begin(),s.end());
    cout << s;
    return 0;
}
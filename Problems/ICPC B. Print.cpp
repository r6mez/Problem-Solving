#include <iostream>
using namespace std;

string print1toN(int n){
    string s = "";
    for (int i = 1; i <= n; i++)
    {
        s += to_string(i);
        if (i != n) s.push_back(' ');
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n; 
    cout << print1toN(n);
    return 0;
}
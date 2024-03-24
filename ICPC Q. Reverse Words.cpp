#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    string s;
    
    getline(cin, s);

    int b = 0;
    for (int i = 0; i <= s.size(); i++)
    {
        if(s[i] == ' ' || i == s.size()){
            reverse(&s[b], &s[i]);
            b = i+1;
        }
    }
    
    cout << s;
    
    return 0;
}
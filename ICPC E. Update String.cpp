#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if(((s[i-1] != 'i' && s[i-1] != 'o' && s[i-1] != 'u' && s[i-1] != 'e' && s[i-1] != 'a')
        && (s[i+1] != 'i' && s[i+1] != 'o' && s[i+1] != 'u' && s[i+1] != 'e' && s[i+1] != 'a')
        && (s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'e' || s[i] == 'a')) && (i != 0 && i != s.length() - 1) ) s.erase(i,1);
    }
    cout << s;
    return 0;
}
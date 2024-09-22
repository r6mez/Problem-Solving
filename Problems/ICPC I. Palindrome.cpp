#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    string s;
    cin >> s;
    int isPil = true;
    for (int i = 0; i < s.length()/2; i++)
    {   
        if(s[i] != s[s.length()-i-1]) isPil = false;
    }
    
    if(isPil) cout << "YES";
    else cout << "NO";
    
    return 0;
}
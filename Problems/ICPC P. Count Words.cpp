#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    string s; 
    getline(cin, s);
    int x = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ' && ((s[i+1] >= 'a' && s[i+1] <= 'z') || (s[i+1] >= 'A' && s[i+1] <= 'Z'))) x++;
    }

    cout << x;
    
    return 0;
}
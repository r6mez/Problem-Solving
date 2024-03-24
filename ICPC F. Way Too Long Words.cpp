#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)
    {    
        string s;
        cin >> s;
        if(s.length() > 10){
            cout << s[0] << s.length() - 2 << s[s.length()-1] << '\n';
        }else{
            cout << s << "\n";
        }
    }
    return 0;
}
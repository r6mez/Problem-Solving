#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int j;
    cin >> j;
    while (j--)
    {
        string s,t;
        cin >> s >> t;
        int maxI = (s.length() > t.length()? s.length() : t.length());
        int minI = (s.length() < t.length()? s.length() : t.length());
        for (int i = 0; i < maxI; i++)
        {
            if(i < minI){
                cout << s[i] << t[i];
            } else {
                if(s.length() == minI) cout << t[i];
                else cout << s[i];
            }
        }
        if(j != 0) cout << "\n";
    }
    
    return 0;
}
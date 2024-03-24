#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int a, b; 
    cin >> a >> b;
    string s;
    cin >> s;

    bool isOkay = true;
    for (int i = 0; i < s.length(); i++)
    {
        if(i != a) {
            if(!(s[i] >= '0' && s[i] <= '9')) isOkay = false;
        } else{
            if (s[i] != '-') isOkay = false;
        }
    }

    if (isOkay) cout << "Yes";
    else cout << "No";
    
    return 0;
}
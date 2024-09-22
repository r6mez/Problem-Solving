#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    for (int i = s.find('\\'); i < s.length(); i++)
    {
        s.erase(i);
    }
    cout << s;
    return 0;
}
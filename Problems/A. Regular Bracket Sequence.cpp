#include <iostream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    string s;
    cin >> s;
    int count = 0;
    int total = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '('){
            count++;
        } else if (s[i] == ')' && count != 0){
            count--;
            total += 2;
        }
    }

    cout << total;
    return 0;
}
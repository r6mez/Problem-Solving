#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    string s;
    cin >> s;

    string newS = "";
    for (int i = 0; i < s.length(); )
    {   
        if(newS.empty()){
            newS.push_back(s[i]);
            i++;
            continue;
        }  
        if (s[i] != s[i+1]) {
            if(newS.back() != s[i]){
                newS.push_back(s[i]);
                i++;
            } else {
                i++;
                newS.pop_back();
            }
            continue;
        } else {
            i += 2;
        }
    }

    cout << newS;
    
    return 0;
}

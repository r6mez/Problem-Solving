#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    string input;
    cin >> input;
    int isHello = true;
    string substring = "";
    string hello = "hello";
    int iOfHello  = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if(input[i] == hello[iOfHello]){
            substring.push_back(input[i]);
            iOfHello++;
        }
    }
    
    if(substring == "hello") cout << "YES";
    else cout << "NO";
    
    return 0;
}
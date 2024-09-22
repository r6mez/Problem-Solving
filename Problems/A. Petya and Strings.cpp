#include <iostream>
#include <cctype> 
#include <string>
    
using namespace std;

void compareTwoStringsLexicographically(){
    string str1,str2;
    cin >> str1 >> str2;
    
    for (int i = 0; i < str1.size(); i++)
    {
        str1[i] = tolower(str1[i]);
        str2[i] = tolower(str2[i]);

        if(str1 != str2){
            if(str1[i] > str2[i]) {
                cout << 1;
                break;
            }
            else if(str1[i] < str2[i]) {
                cout << -1;
                break;
            }
        } else {
            cout << 0;
            break;
        }
    }
}

int main(){
    compareTwoStringsLexicographically();
    return 0;
}
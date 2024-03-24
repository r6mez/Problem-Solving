#include <iostream> 
#include <ctype.h>
using namespace std;

bool findCharInString(string str, char character){
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] == character) return true;
    }    
    return false;
}

void checkIsPangram(){
    int num;
    cin >> num;

    cin.ignore();

    string input;
    cin >> input;

    for (int i = 0; i < input.size(); i++)
    {
        input[i] = tolower(input[i]);
    }
    
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    bool isPangram = true;

    for(int i = 0; i < alphabet.size(); i++){
        if(!findCharInString(input, alphabet[i])){
            isPangram = false;
        }
    }

    if(isPangram) cout << "YES";
    else cout << "NO";
}


int main(){
    checkIsPangram();
    return 0;
}
#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

int checkCharRepeatition(string word, char charcter){
    int repeatNumber = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if(word[i] == charcter) repeatNumber++;
    }
    
    return repeatNumber;
}


void boyOrGirl(){
    string username;
    cin >> username;

    int distinctChars = 0;
    for (int i = 0; i < username.length(); i++)
    {
        int repeatNumber = checkCharRepeatition(username,username[i]);   
        if (repeatNumber == 1) distinctChars++;
    }


    if (distinctChars % 2 != 0) cout << "IGNORE HIM!";
    else cout << "CHAT WITH HER!";    
}


int main(){
    boyOrGirl();
    return 0;
}
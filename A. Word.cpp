#include <iostream> 
using namespace std;

void wordFormatting(){
    string word;
    cin >> word;

    int uppers = 0;
    int lowers = 0;

    for (int i = 0; i < word.length(); i++)
    {
        if(isupper(word[i])) uppers++;
        else lowers++;
    }
    
    if(uppers > lowers){
        for (int i = 0; i < word.length(); i++)
        {
           word[i] = toupper(word[i]);
        }
    } else {
        for (int i = 0; i < word.length(); i++)
        {
            word[i] = tolower(word[i]);
        }
    }
    
    cout << word;
}

int main(){
    wordFormatting();
    return 0;
}
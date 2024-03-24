#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;


void checkIsReversed(){
    string word, reversed;
    cin >> word >> reversed;

    bool isReversed = true;
    for (int i = 0; i < word.length(); i++)
    {
        if(word.length() != reversed.length() || word[i] != reversed[word.length() - i - 1]) {
            isReversed = false;
            break;
        };
    }
    
    if(isReversed) cout << "YES";
    else cout << "NO";
}


int main(){
    checkIsReversed();
    return 0;
}
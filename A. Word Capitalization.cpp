#include <iostream> 
#include <vector>
using namespace std;

void WordCapitalization(){
    string word;
    cin >> word;

    word[0] = toupper(word[0]);

    cout << word;
}



int main(){
    WordCapitalization();
    return 0;
}
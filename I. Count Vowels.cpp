#include <iostream>
using namespace std;

void countVowels(string s, int i = 0, int vowels = 0){
    if(i >= s.size()) {
        cout << vowels;
        return;
    }
    char c = tolower(s[i]);
    if(c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'e') vowels++;
    countVowels(s, ++i, vowels);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    countVowels(s);
    return 0;
}
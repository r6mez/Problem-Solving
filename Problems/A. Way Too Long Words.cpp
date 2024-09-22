#include <iostream>
#include <vector>
using namespace std; 

void shrinkWords(vector<string> words){
    for (int i = 0; i < words.size(); i++)
   {
    string shrinkedWord = "";
    if (words[i].size() > 10) {
        shrinkedWord += words[i][0];
        shrinkedWord += to_string(words[i].length() - 2);
        shrinkedWord += words[i].back();
        cout << shrinkedWord << endl;
    } else{
        cout << words[i] << endl;
    }
   }
}

vector<string> getWords(){
    int numberOfWords = 0;
    cin >> numberOfWords;
    vector<string> words;
    for (int i = 0; i < numberOfWords; i++)
    {
        string word;
        cin >> word;
        words.push_back(word);
    }
    return words;
}

int main(){
    shrinkWords(getWords());
    return 0;
}

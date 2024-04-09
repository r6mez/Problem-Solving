// #include <iostream> 
// #include <ctype.h>
// using namespace std;

// bool findCharInString(string str, char character){
//     for (int i = 0; i < str.size(); i++)
//     {
//         if(str[i] == character) return true;
//     }    
//     return false;
// }

// int main(){
//     int num;
//     cin >> num;

//     cin.ignore();

//     string input;
//     cin >> input;

//     for (int i = 0; i < input.size(); i++)
//     {
//         input[i] = tolower(input[i]);
//     }
    
//     string alphabet = "abcdefghijklmnopqrstuvwxyz";

//     bool isPangram = true;

//     for(int i = 0; i < alphabet.size(); i++){
//         if(!findCharInString(input, alphabet[i])){
//             isPangram = false;
//         }
//     }

//     if(isPangram) cout << "YES";
//     else cout << "NO";
//     return 0;
// }


// Secend approch using freq-array
#include <iostream>
#include <string>
using namespace std;

int main (){
    int n;
    cin >> n;
    string s; cin >> s;
    if(n < 26){
        cout << "NO";
    } else {
        int freqS[200] = {0};
        for (int i = 0; i < n; i++)
        {
            freqS[tolower(s[i])]++;
        }
        
        bool isPangram = true;
        for (int i = 'a'; i <= 'z'; i++)
        {
            if(freqS[i] == 0) {
                isPangram = false;
                break;
            }
        }

        if(isPangram) cout << "YES";
        else cout << "NO";
    }
    return 0;
}
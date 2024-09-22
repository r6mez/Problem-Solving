#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

void whoWinsInChess(){
    int numberOfGames;
    cin >> numberOfGames;

    string results;
    cin >> results; 


    int Anton = 0;
    int Danik = 0;
    for (char i : results)
    {
        if (i == 'A') Anton++;
        else Danik++;
    }

    if (Anton > Danik) cout << "Anton";
    else if (Danik > Anton) cout << "Danik";
    else cout << "Friendship";
}


int main(){
    whoWinsInChess();
    return 0;
}
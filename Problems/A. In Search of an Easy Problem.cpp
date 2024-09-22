#include <iostream> 
#include <vector>
using namespace std;

vector<int> getInputOfIntegers(int numberOfIntegers) {
    vector <int> results;
    for (int i = 0; i < numberOfIntegers; i++)
    {
        int input;
        cin >> input;
        results.push_back(input);
    }
    return results;
}

void easyOrHard(){
    int people;
    cin >> people;
    vector<int> votes = getInputOfIntegers(people);


    bool isEasy = true;
    for (int vote = 0; vote < votes.size(); vote++)
    {
        if(votes[vote] == 1){
            isEasy = false;
            break;
        }
    }
    
    if(isEasy) cout << "EASY";
    else cout << "HARD";
}


int main(){
    easyOrHard();
    return 0;
}
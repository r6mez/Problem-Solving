#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

vector<int> getInputOfIntegers() {
    string input;
    getline(cin, input);
    vector<int> result;
    istringstream iss(input);
    int num;
    while (iss >> num) {
        result.push_back(num);
    }
    return result;
}

void beautifulMatrix(){
    //input
    vector<int> playersNumberAndWinnerRank = getInputOfIntegers();
    vector<int> scores = getInputOfIntegers();
   
    int numberOfplayers = playersNumberAndWinnerRank[0];
    int winnerRank = playersNumberAndWinnerRank[1];
    int winnerScore = scores[winnerRank - 1];
    int numberofWinners = 0;

    for(int i: scores){
        if (i >= winnerScore && i != 0){
            numberofWinners++;
        }
    }
    
    cout << numberofWinners;       
}


int main(){
    beautifulMatrix();
    return 0;
}
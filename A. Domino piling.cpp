#include <iostream> 
#include <vector>
#include <sstream>
#include <math.h>
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
    vector<int> MandN = getInputOfIntegers();
    int boardSize = MandN[0] * MandN[1];
    int dominoSize = 2;

    int dominosNumber = floor(boardSize/dominoSize);
    cout << dominosNumber;
}


int main(){
    beautifulMatrix();
    return 0;
}
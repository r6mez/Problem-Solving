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

void calcWidth(){
    vector<int> numberOfbrosANDheightOfThefence = getInputOfIntegers();
    int numberOfbros = numberOfbrosANDheightOfThefence[0]; 
    int heightOfThefence = numberOfbrosANDheightOfThefence[1];

    vector<int> brosHeights = getInputOfIntegers();

    int bendedbros = 0;
   
    for (int i = 0; i < brosHeights.size(); i++){
        if (brosHeights[i] > heightOfThefence) bendedbros++; 
    }

    int width = 0;
    
    width += (numberOfbros - bendedbros);
    width += (bendedbros * 2);

    cout << width;
}

int main(){
    calcWidth();
    return 0;
}
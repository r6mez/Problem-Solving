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
    vector<vector<int>> matrix;
    int moves = 0;

    //form the matrix
    for (int i = 0; i < 5; i++) matrix.push_back(getInputOfIntegers());


    //find the 1
    for (int column = 0; column < 5; column++)
    {
        for (int row = 0; row < 5; row++)
        {
            if(matrix[column][row] == 1){
                moves += abs((column + 1) - 3);
                moves += abs((row + 1) - 3);

            }
        }
        
    }
    
    cout << moves;
}



int main(){
    beautifulMatrix();
    return 0;
}
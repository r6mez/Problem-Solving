#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;


void countRemovedStones(){
    int numberOfStones;
    cin >> numberOfStones;

    string stonesColors;
    cin >> stonesColors;
    
    int stonesShouldBeRemoved = 0;
    for (int i = 0; i < stonesColors.length(); i++)
    {
        if(stonesColors[i] == stonesColors[i+1]){
            stonesShouldBeRemoved++;
        }
    }
    
    cout << stonesShouldBeRemoved;
}



int main(){
    countRemovedStones();
    return 0;
}
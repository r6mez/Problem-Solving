#include <iostream> 
#include <vector>
using namespace std;

void calcMagnetGroups(){
    int numberOfMagnets;
    cin >> numberOfMagnets;

    vector<int> magnets;

    for (int i = 0; i < numberOfMagnets; i++)
    {
        int magnetCode;
        cin >> magnetCode;
        magnets.push_back(magnetCode);
    }

    int groups = 1;

    for (int i = 0; i < magnets.size() - 1; i++)
    {       
        if(magnets[i] != magnets[i+1]) groups++;
    }
    
    cout << groups;
}



int main(){
    calcMagnetGroups();
    return 0;
}
#include <iostream> 
#include <vector>
using namespace std;

void calcStepsUntilDivison(){
    int cases;
    cin >> cases;

    vector<int> results = {};

    for (int i = 0; i < cases; i++)
    { 
        int a, b;
        cin >> a >> b;

        int steps = 0;

        if(b < a){
            if(a%b != 0){
                steps = ((a - (a % b)) + b) - a;
            } else steps = 0;
        } 
        else if (b > a) steps = b - a;
        else steps = 0;

        results.push_back(steps);
    }

    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }
    
}

int main(){
    calcStepsUntilDivison();
    return 0;
}
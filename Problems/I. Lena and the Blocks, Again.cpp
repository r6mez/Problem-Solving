#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long towers[n];
    
    // input and find max and min values
    long long max = 0, min = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {   
        cin >> towers[i];
        if(max < towers[i]) {
            max = towers[i];
        }
        if(min >= towers[i]){
            min = towers[i];
        }
    }
 
    // find all indexes of the max values and min values and store them in array
    vector<int> indeces;
    
    for (int i = 0; i < n; i++)
    {
        if(towers[i] == max || towers[i] == min) indeces.push_back(i);
    }

    
    int changed = false;
    int minLength = INT_MAX;
    for (int i = 0; i < indeces.size()-1; i++)
    {
        int diff = (indeces[i+1] - indeces[i]);
        if(minLength > diff && towers[indeces[i+1]] != towers[indeces[i]]){
            minLength = diff;
            changed = true;
        } 
    }
    cout << (changed? minLength : 0) << endl;
    return 0;
}
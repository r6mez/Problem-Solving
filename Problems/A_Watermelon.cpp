#include <iostream>
using namespace std; 

string canBeDevidedIntoTwoEven(int w){
    int part1,part2;

    for (int i = 1; i < w; i++)
    {
        part1 = i;
        part2 = w-i;
        if(part1 % 2 == 0 && part2 % 2 == 0){
            return "YES";
        } 
    }
    return "NO";
}


int main(){
    int w;
    cin >> w;
    cout << canBeDevidedIntoTwoEven(w);
    return 0;
}

#include <iostream> 
using namespace std;

void expressEmotions(){
    int layers;
    cin >> layers;

    string emotions = "";

    for (int i = 1; i <= layers; i++)
    {
        if (i % 2 != 0){
            emotions += "I hate ";
        } else {
            emotions += "I love ";
        }

        if (i != layers){
            emotions += "that ";
        } else {
            emotions += "it ";
        }
    }

    cout << emotions;
}


int main(){
    expressEmotions();
    return 0;
}
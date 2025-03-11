#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

void calcDamegedDragons(){
    int k, l, m, n, d;
    cin >> k;
    cin >> l;
    cin >> m;
    cin >> n;
    cin >> d;

    int damegedDragons = 0;

    for (int i = 1; i <= d; i++)
    {
        if(i%k==0 || i%l==0 || i%m==0 || i%n==0){
            damegedDragons++;
        }
    }

    cout << damegedDragons;
}


int main(){
    calcDamegedDragons();
    return 0;
}
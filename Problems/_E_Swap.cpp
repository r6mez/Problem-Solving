#include <iostream>

using namespace std;

void My_Swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int x, y;
    cin >> x >> y;
    My_Swap(x,y);
    cout << x << " " << y;    
    return 0;
}
#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

int calcBananasCouldBeBought(int soldiersMoney, int costOfFirstBanana){
    int BananasCouldBeBought = 0;
    while (soldiersMoney > 0){
        soldiersMoney = soldiersMoney - (costOfFirstBanana * BananasCouldBeBought);
        if(soldiersMoney > 0){
            BananasCouldBeBought++;
        }
    }
    return BananasCouldBeBought;
}

void countBorrowedMoney(){
    int costOfFirstBanana, soldiersMoney, wantedBananas;
    cin >> costOfFirstBanana >> soldiersMoney >> wantedBananas;

    int BananasCouldBeBought = calcBananasCouldBeBought(soldiersMoney,costOfFirstBanana);

    int totalcost = 0;
    for (int i = 1; i <= wantedBananas; i++)
    {
        totalcost = totalcost + (costOfFirstBanana * i);
    }

    int borrowedMoney = totalcost - soldiersMoney;
    
    if (borrowedMoney < 0 ) borrowedMoney = 0;
    
    cout << borrowedMoney;
}

int main(){
    countBorrowedMoney();
    return 0;
}
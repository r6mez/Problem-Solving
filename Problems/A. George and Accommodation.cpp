#include <iostream> 
using namespace std;


void accomodationAvaliablity(){
    int rooms;
    cin >> rooms;

    int avaliableRooms = 0;

    for (int i = 0; i < rooms; i++)
    {
        int peopleInTheRooms, roomCapacity;
        cin >> peopleInTheRooms >> roomCapacity;
        if((roomCapacity - peopleInTheRooms) >= 2){
            avaliableRooms++;
        }
    }

    cout << avaliableRooms;
}


int main(){
    accomodationAvaliablity();
    return 0;
}
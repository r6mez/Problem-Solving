#include <iostream> 
using namespace std;

void findBeautifulYear(){
    int year;
    cin >> year;

    year++;
    string yearText = to_string(year);

    bool isDistinct = false;

    while (isDistinct != true){   
        for (int digit = 0; digit < yearText.length(); digit++)
        {
            for (int nextdigit = digit+1; nextdigit < yearText.length(); nextdigit++)
            {
                if(yearText[digit] != yearText[nextdigit]) isDistinct = true; 
                else {
                    isDistinct = false;
                    break;
                }
            }
            if(!isDistinct) break;
        }
        if(!isDistinct){
            year++;
            yearText = to_string(year);
        }
    }

    cout << year;
         
}


int main(){
    findBeautifulYear();
    return 0;
}
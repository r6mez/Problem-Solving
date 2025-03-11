#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    string working[3];
    string services[4] = {"Facebook","Instagram","WhatsApp","Messenger"};
    for (int i = 0; i < 3; i++)
    {
        cin >> working[i];
    }

    for (int i = 0; i < 4; i++)
    {
        bool found = false;
        for (int k = 0; k < 3; k++)
        {
            if(services[i] == working[k]) found = true;
        }
        if(!found) cout << services[i];
    }
    
    return 0;
}
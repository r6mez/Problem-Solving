    #include <iostream> 
    using namespace std;


    void rearrangeQueue(){
        int numberOfStudents, secoends;
        cin >> numberOfStudents >> secoends;
        string queueData;
        cin >> queueData;
        for (int secondsPassed = 0; secondsPassed < secoends; secondsPassed++)
        {
            for (int student = 0; student < numberOfStudents; student++)
            {
                if(queueData[student] == 'B' && queueData[student+1] == 'G'){
                    //swap
                    int temp;
                    temp = queueData[student];
                    queueData[student] = queueData[student+1];
                    queueData[student+1] = temp; 
                    student++;
                }
            }
        }

        cout << queueData;
    }


    int main(){
        rearrangeQueue();
        return 0;
    }
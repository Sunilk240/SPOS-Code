#include<iostream>
using namespace std;
#define max 5

void signal(int &x){
    x++;
}

void wait(int &x){
    if(x>0)
        x--;
}

class Semaphore{
public:
    int buffer[max];
    int empty = max;
    int full = 0;
    int mutex = 1;

    void producer(){
        cout<<"Empty: "<<empty<<"  Full: "<<full<<"  Mutex: "<<mutex;
        if (empty!=0 && mutex == 1){
            wait(empty);
            wait(mutex);
            cout<<"Enter item to produce: ";
            cin>>buffer[full];
            signal(mutex);
            signal(full);
        }       
    }

    void consumer(){
        cout<<"Empty: "<<empty<<"  Full: "<<full<<"  Mutex: "<<mutex;
        if (full!=0 && mutex == 1){
            wait(full);
            wait(mutex);
            cout<<"Item Consumed is: "<<buffer[full];
            signal(mutex);
            signal(empty);
        } 
    }
};

int main(){
    Semaphore s;
    int ch;
    while(true){
    cout<<"\n ----- ----- MENU ----- ----- \n";
    cout<<"1.Producer\n2.Consumer\n3.Exit\nEnter choice: ";
    cin>>ch;
    if (ch ==1)
        s.producer();
    else if (ch ==2)
        s.consumer();
    else if (ch ==3)
        break; 
    else
        cout<<"\nInvalid choice\n";
    }
    return 0;
}


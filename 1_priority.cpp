#include<iostream>
using namespace std;
#define max 10
int main(){

    int P[max],CT[max],AT[max],BT[max],TAT[max],WT[max],is_comp[max],ST[max],Priority[max],index,curr_time=0,completed =0; 
    float AvgWT=0, AvgTAT=0, Pno;
    
    int x=0;
    cout<<"\n ---- ---- MENU ---- ----\n";
    cout<<"Enter number of processes: ";
    cin>>Pno;
    for(int i=0;i<Pno;i++){
        P[i]=i+1;
        cout<<"Enter Arrival time of P"<<i+1;
        cin>>AT[i];
        cout<<"Enter Burst time of P"<<i+1;
        cin>>BT[i];
        cout<<"Enter Priority of P"<<i+1;
        cin>>Priority[i];
    }

    cout<<"\nPriority\tProcess No.\tArrival Time\tBurst Time";
    for(int i=0;i<Pno;i++){
        cout<<"\n"<<Priority[i]<<"\t\t"<<P[i]<<"\t\t"<<AT[i]<<"\t\t"<<BT[i];
    }

    for(int i=0;i<Pno;i++){
        is_comp[i]=0;
    }
    
    cout<<"\n --------  GANTT CHART  --------\n";
    while(completed<Pno){
        int maxP = -1;
        for(int i=0;i<Pno;i++){
            if(AT[i]<=curr_time && is_comp[i] == 0){
                if(Priority[i]>maxP){
                    maxP = Priority[i];
                    index = i;
                }
                if(Priority[i]==maxP){
                    if(AT[i]<AT[index]){
                        maxP = Priority[i];
                        index = i;
                    }
                }
            }
        }
        if(maxP == -1){
            curr_time++;
        }
        else{
            ST[index] = curr_time;
            CT[x] = ST[index] + BT[index];
            TAT[index] = CT[x] - AT[index];
            cout<<"curr --->"<<curr_time;
            WT[index] = TAT[index] - BT[index];
            is_comp[index] = 1;
            completed++;
            curr_time=CT[x];

            x++;
            cout<<"|  P"<<P[index]<<"\t";
        }
    }
    cout<<"|\n0\t";
    for(int i=0;i<Pno;i++){
        cout<<CT[i]<<"\t";
    }

    for(int i=0;i<Pno;i++){
        cout<<"\nWaiting time for P"<<P[i]<<": "<<WT[i];
        AvgWT+=WT[i];
    }
    cout<<"\nAvg WT:   "<<AvgWT/Pno;
    for(int i=0;i<Pno;i++){
        cout<<"\nTurn Around time for P"<<P[i]<<": "<<TAT[i];
        AvgTAT+=TAT[i];
    }
    cout<<"\nAvg TAT:   "<<AvgTAT/Pno;

    return 0;
}
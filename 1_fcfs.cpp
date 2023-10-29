#include<iostream>
using namespace std;
#define max 10
int main(){

    int P[max],CT[max],AT[max],BT[max],TAT[max],WT[max]; 
    float AvgWT=0, AvgTAT=0, Pno;

    cout<<"\n ---- ---- MENU ---- ----\n";
    cout<<"Enter number of processes: ";
    cin>>Pno;
    for(int i=0;i<Pno;i++){
        P[i]=i+1;
        cout<<"Enter Arrival time of P"<<i+1;
        cin>>AT[i];
        cout<<"Enter Burst time of P"<<i+1;
        cin>>BT[i];
    }

    cout<<"\nProcess No.\tArrival Time\tBurst Time";
    for(int i=0;i<Pno;i++){
        cout<<"\n"<<P[i]<<"\t\t"<<AT[i]<<"\t\t"<<BT[i];
    }

    for(int i=0;i<Pno;i++){
        for(int j=i+1;j<Pno;j++){
            if(AT[i]>AT[j]){
                swap(AT[i],AT[j]);
                swap(BT[i],BT[j]);
                swap(P[i],P[j]);
            }
        }
    }
    CT[0] = 0;
    for(int i=0 ;i<Pno;i++){
        CT[i+1] = CT[i]+ BT[i];
        TAT[i]=CT[i+1]-AT[i];
        WT[i]=TAT[i]-BT[i];
    }

    cout<<"\n --------  GANTT CHART  --------\n";
    for(int i=0;i<Pno;i++){
        cout<<"|  P"<<P[i]<<"\t";
    }
    cout<<"|\n";
    for(int i=0;i<=Pno;i++){
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
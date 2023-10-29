#include<iostream>
using namespace std;


int main(){
    
    int m, n;

    cout<<"Enter Number of Blocks :";
    cin>>n;
    int blockSize[n];
    for(int i = 0; i<n;i++){
        cout<<"Enter size of BlockSize ["<<i<<"]";
        cin>>blockSize[i];
    }
    
    cout<<"Enter Number of Processes :";
    cin>>m;
    int processSize[m];
    for(int i = 0; i<m;i++){
        cout<<"Enter size of Process ["<<i<<"]";
        cin>>processSize[i];
    }

    int tbs[n];
    for(int i=0;i<n;i++){
        tbs[i] = blockSize[i];
    }


    int address[n];
    address[0]=0;
    for(int i=1;i<n;i++){
        address[i]=address[i-1]+blockSize[i-1];
    }
    int total = address[n-1]+blockSize[n-1];


    int allocation[m];
    for(int i=0;i<m;i++)
        allocation[i]=-1;

    int ptr = -1; 
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ptr = (ptr + 1) % n;
            if(blockSize[ptr]>processSize[i]){
                allocation[i]=ptr;
                blockSize[ptr]-=processSize[i];
                break;
            }
        }
    }


    cout<<"\nProcesses\tProcess Size\tBlock No.\t";
    for(int i =0;i<m;i++){
        cout<<"\nP"<<i<<"\t\t"<<processSize[i]<<"\t\t";
        if(allocation[i]!=-1)
            cout<<allocation[i];
        else
            cout<<"Not allocated";
    }


    cout<<"\n\nBlock No.\tAllocation\tAddress";
    for(int i=0;i<n;i++){
        cout<<"\n"<<i<<"\t\t";
        for(int x=0;x<m;x++){
            if(allocation[x]!=-1){
                if(allocation[x]==i)
                    cout<<"p"<<x;
            }
            else{
                cout<<"["<<tbs[i]<<"]";
                break;
            }
        }
        cout<<"\t\t";
        cout<<address[i];
    }

    cout<<"\n total: "<<total;
    float used=0;
    for (int i=0;i<m;i++){
        if(allocation[i]!=-1){
            used += processSize[i];
        }
    }
    cout<<"\nused: "<<used;
    cout<<"\nMemory utilization: "<<used/total;


    return 0;
}
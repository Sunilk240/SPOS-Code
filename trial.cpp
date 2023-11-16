#include<iostream>
using namespace std;


void print(int m,int n,int allocation[],int processSize[],int blockSize[],int address[],int total){
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
}

void ff(int m,int n,int processSize[],int blockSize[],int address[],int total){
    int allocation[m];
    for(int i=0;i<m;i++)
        allocation[i]=-1;
        
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(processSize[i]<blockSize[j]){
                allocation[i]=j;
                blockSize[j]-=processSize[i];
                break;
            }
        }    
    }

    print(m,n,allocation,processSize,blockSize,address,total);
}

void wf(int m,int n,int processSize[],int blockSize[],int address[],int total){
    int allocation[m];
    for(int i=0;i<m;i++)
        allocation[i]=-1;

    for(int i=0;i<m;i++){
        int worstInd = -1;
        for(int j=0;j<n;j++){
            if(processSize[i]<=blockSize[j]){
                if(worstInd == -1 || blockSize[worstInd]<blockSize[j])
                        worstInd = j;
            }
        } 
        if(worstInd!=-1){
            allocation[i]=worstInd;
            blockSize[worstInd]-=processSize[i];
        }   
    }

    print(m,n,allocation,processSize,blockSize,address,total);
}



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
    
    int address[n];
    address[0]=0;
    for(int i=1;i<n;i++){
        address[i]=address[i-1]+blockSize[i-1];
    }

    int total = address[n-1]+blockSize[n-1];



    //ff(m,n,processSize,blockSize,address,total);
    wf(m,n,processSize,blockSize,address,total);

    return 0;
}
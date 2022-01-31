#include<iostream>
using namespace std;
int main(void) {
    int n,bt[20],wt[50],tat[50],avgwt=0,avgtt=0,i,j;
    cout<<"Enter the total no. of processes: ";
    cin>>n;
    cout<<"\nEnter Process Burst Time-> \n";
    for (i=0;i<n;i++) {
        cout<<"P("<<i+1<<"): ";
        cin>>bt[i];
    }
    wt[0]=0;
    for (i=1;i<n;i++) {
        wt[i]=0;
        for (j=0;j<i;j++)
        wt[i]+=bt[j];
    }
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";
    //calculating turnaround time
    for (i=0;i<n;i++) {
        tat[i]=bt[i]+wt[i];
        avgwt+=wt[i];
        avgtt+=tat[i];
        cout<<"\nP("<<i+1<<")"<<"\t\t\t"<<bt[i]<<"\t\t\t"<<wt[i]<<"\t\t\t\t"<<tat[i];
    }
    avgwt/=i;
    avgtt/=i;
    cout<<"\n\nAverage Waiting Time: "<<avgwt;
    cout<<"\n\nAverage Turnaround Time: "<<avgtt<<endl;
}
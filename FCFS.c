/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include<stdio.h>  
// Function to find the waiting time for allprocesses  
void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[])  
{  

    wt[0] = 0;  
    int service_time[n]; 
    service_time[0] = 0;
    for (int  i = 1; i < n ; i++ )
    {
        service_time[i] = service_time[i-1] + bt[i-1];
        wt[i] = service_time[i] - at[i];  
        
    }
}  
    
// Function to calculate turn around time  
void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])  
{  
    
    for (int  i = 0; i < n ; i++)  
        tat[i] = bt[i] + wt[i];  
}  
    
//Function to calculate average time  
void findavgTime( int processes[], int n, int bt[], int at[])  
{  
    int wt[n], tat[n], total_wt = 0, total_tat = 0;  
    
    findWaitingTime(processes, n, bt, wt, at);  
    
    
    findTurnAroundTime(processes, n, bt, wt, tat);  
    
    for (int  i=0; i<n; i++)  
    {  
        total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
    
    }  
    float s=(float)total_wt / (float)n; 
    float t=(float)total_tat / (float)n; 
    printf("Average waiting time = %f",s); 
    printf("\n"); 
    printf("Average turn around time = %f ",t);  
}  
    
// main fucntion to execute the code  
int main()  
{  
    int processes[] = { 1, 2, 3, 4, 5};  
    int n = sizeof processes / sizeof processes[0];  
    
    //Burst time of all processes  
    int  burst_time[] = {6, 3, 8, 3, 4}; 
    //Arrival time of all processes 
    int arrival_time[] = {2 ,5 ,1 ,0 ,4};
    findavgTime(processes, n,  burst_time, arrival_time);  
    return 0;  
}  
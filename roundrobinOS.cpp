#include<iostream>
// round robin al
using namespace std;
struct process{
	int id;
	int arivalTime;
	int burst_time;
	int completition_time;
	int turnaround_time;
	int waiting_time;
};
void calculate_time(process processes[], int n, int quantum);
void calculate_TAT(process processes[], int n);
void calculate_WT(process processes[], int n);
void printTable(process processes[], int n);
int main(){
int n, tq;
cout<<"Enter the number of processes"<<endl;
cin>>n;
cout<<"Enter the time quantum"<<endl;
cin>>tq;
// make an array of structure with the length= number of processes
process processes[n];
for(int i=0;i<n;i++){
	cout<<"process"<<i+1<<endl;
	processes[i].id=i+1;
	cout<<"Enter the arrival time for "<<i+1<<"process"<<endl;
	cin>>processes[i].arivalTime;
	cout<<"Enter the burst time for "<<i+1<<"process"<<endl;
	cin>>processes[i].burst_time;

	}
	calculate_time(processes,n,tq);// to calculate completition time
	calculate_TAT(processes,n);// function used to calculate turnaround time for all the processes
	calculate_WT(processes,n);// to calculate waiting time
	printTable(processes,n);
	
}
void calculate_TAT(process processes[], int n)	{
	for(int i=0;i<n;i++){
		processes[i].turnaround_time= processes[i].completition_time-processes[i].arivalTime;
	}
}
void calculate_WT(process processes[], int n)	{
	for(int i=0;i<n;i++){
		processes[i].waiting_time= processes[i].turnaround_time-processes[i].burst_time;
	}
}
void calculate_time(process processes[], int n, int quantum){
	int remaining_time[n];
	for(int i=0;i<n;i++){
		remaining_time[i]=processes[i].burst_time;
	}
	int curr_time=0;
	bool allDone=false;//take of execution of all the processes
	while(!allDone){
		allDone=true;
		for(int i=0;i<n;i++){
			if(remaining_time[i]>0){
				allDone=false;
				if(remaining_time[i]>quantum){
					curr_time=curr_time+quantum;
					remaining_time[i]=remaining_time[i]-quantum;
				}
				else{
					curr_time= curr_time+remaining_time[i];
					processes[i].completition_time=curr_time;
					remaining_time[i]=0;
				}
			}
		}
	}
}
void printTable(process processes[], int n){
	for(int i=0;i<n;i++){
		cout<<processes[i].id<<" "<< processes[i].arivalTime<<" "<<processes[i].burst_time<<" "<<processes[i].completition_time<<" "<<processes[i].turnaround_time<<" "<<	processes[i].waiting_time<<endl;
	}
}


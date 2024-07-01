#include<iostream>
// sjf
using namespace std;
struct process{
	int id;
	int arivalTime;
	int start_time;
	int burst_time;
	int completition_time;
	int turnaround_time;
	int waiting_time;
};

void printTable(process processes[], int n);
int main(){
int n;
cout<<"Enter the number of processes"<<endl;
cin>>n;

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
	bool is_completed[n];
	int curr_time=0;
	int completed=0;// to keep record of number of complted process
	while(completed!=n){
		// find the process with least bt till the current time
		int min_ind=-1;// index of the process with mininmum burst time
		int minimum=1000000;// the bt of the process with min bt
		for(int i=0;i<n;i++){
			if(processes[i].arivalTime<=curr_time&&is_completed[i]==0){
				if(processes[i].burst_time<minimum){
					minimum= processes[i].burst_time;
					min_ind=i;
				}
				if(processes[i].burst_time==minimum){
					if(processes[i].arivalTime<processes[min_ind].arivalTime){
						minimum= processes[i].burst_time;
						min_ind=i;
					}
				}
				
				
			}
		}
		if(min_ind==-1){
			// the required process is not found
			curr_time++;
		}
		if(min_ind!=-1){// the process with min burst time is found
			processes[min_ind].start_time= curr_time;
			processes[min_ind].completition_time= processes[min_ind].start_time+processes[min_ind].burst_time;
			processes[min_ind].turnaround_time=processes[min_ind].completition_time-processes[min_ind].arivalTime;
			processes[min_ind].waiting_time=processes[min_ind].turnaround_time-processes[min_ind].burst_time;
			completed++;
			is_completed[min_ind]=true;
			curr_time=processes[min_ind].completition_time;
		}
	}
	
	printTable(processes,n);
}
void printTable(process processes[], int n){
	for(int i=0;i<n;i++){
		cout<<processes[i].id<<" "<< processes[i].arivalTime<<" "<<processes[i].burst_time<<" "<<processes[i].completition_time<<" "<<processes[i].turnaround_time<<" "<<	processes[i].waiting_time<<endl;
	}
}

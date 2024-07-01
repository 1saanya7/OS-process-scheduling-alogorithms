#include <iostream>
using namespace std;
void FirstComeFirstServe(int at[], int bt[], int size);

int main() {
  int size = 0;
  cout << "Enter No. of processes ";
  cin >> size;

  int at[size];
  int bt[size];

  for (int i = 0; i < size; i++) {
    cout << "Enter Arrival time of process " << i + 1 << " : ";
    cin >> at[i];
    cout << "Enter Burst time of process " << i + 1 << " : ";
    cin >> bt[i];
  }

  FirstComeFirstServe(at, bt, size);
}

void FirstComeFirstServe(int at[], int bt[], int size) {

  int wt[size];
  wt[0] = 0;

  for (int i = 1; i < size; i++) {
    wt[i] = (at[i - 1] + bt[i - 1] + wt[i - 1]) - at[i];
  }

  for (int j = 0; j < size; j++) {
    cout << "Waiting time of process " << j + 1 << " : " << wt[j] << endl;
  }

  float avgwait = 0;
  for (int i = 0; i < size; i++) {
    avgwait = avgwait + wt[i];
  }

  avgwait = avgwait / size;

  cout << "Average waiting Time : " << avgwait << endl;
}

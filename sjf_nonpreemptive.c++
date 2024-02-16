#include <iostream>

using namespace std;

void SJF_nonpreemptive(int ids[], int arrival_time[], int burst_time[], int n) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    int currentTime = 0;

    cout << "Process    Arrival Time    Burst Time    Waiting Time    Turnaround Time\n";

    for (int i = 0; i < n; ++i) {
        int shortest = -1;
        for (int j = 0; j < n; ++j) {
            if (arrival_time[j] <= currentTime && burst_time[j] > 0) {
                if (shortest == -1 || burst_time[j] < burst_time[shortest]) {
                    shortest = j;
                }
            }
        }
        if (shortest == -1) {
            currentTime++;
            i--;
            continue;
        }
        totalWaitingTime += currentTime - arrival_time[shortest];
        totalTurnaroundTime += currentTime + burst_time[shortest] - arrival_time[shortest];
        currentTime += burst_time[shortest];
        cout << ids[shortest] << "           " << arrival_time[shortest] << "              " << burst_time[shortest] << "              " << currentTime - arrival_time[shortest] - burst_time[shortest] << "                 " << currentTime - arrival_time[shortest] << endl;
        burst_time[shortest] = 0; // process completed
    }

    cout << "\nAverage Waiting Time: " << (double)totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << (double)totalTurnaroundTime / n << endl;
}

int main() {
    int ids[] = {1, 2, 3, 4};
    int arrival_time[] = {0, 2, 4, 6};
    int burst_time[] = {6, 4, 8, 3};
    int n = sizeof(ids) / sizeof(ids[0]);

    cout << "Shortest Job First (Non-preemptive) Scheduling Algorithm\n\n";
    SJF_nonpreemptive(ids, arrival_time, burst_time, n);
    return 0;
}

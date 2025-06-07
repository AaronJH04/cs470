#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for a process
typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int is_completed;
} Process;

int n; // Number of processes

// Find next process with the shortest remaining time at current time
int findNextProcess(Process proc[], int current_time) {
    int shortest = -1;
    int min_time = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (proc[i].arrival_time <= current_time && !proc[i].is_completed && proc[i].remaining_time < min_time) {
            min_time = proc[i].remaining_time;
            shortest = i;
        }
    }
    return shortest;
}

// Preemptive SJF (Shortest Remaining Time First)
void srtf(Process proc[]) {
    int completed = 0, current_time = 0;
    for (int i = 0; i < n; i++) {
        proc[i].remaining_time = proc[i].burst_time;
        proc[i].is_completed = 0;
    }
    printf("Execution order (SJF): ");
    while (completed < n) {
        int idx = findNextProcess(proc, current_time);
        if (idx == -1) {
            current_time++;
            continue;
        }
        printf("P%d ", proc[idx].process_id);
        proc[idx].remaining_time--;
        current_time++;
        if (proc[idx].remaining_time == 0) {
            proc[idx].is_completed = 1;
            completed++;
            int finish_time = current_time;
            proc[idx].turnaround_time = finish_time - proc[idx].arrival_time;
            proc[idx].waiting_time = proc[idx].turnaround_time - proc[idx].burst_time;
        }
    }
    printf("\n");
}

// Function to print the processes and their details
void printProcesses(Process proc[]) {
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].process_id, proc[i].arrival_time, proc[i].burst_time,
               proc[i].waiting_time, proc[i].turnaround_time);
    }
}

int main() {
    // Initialize processes with their IDs, arrival times, and burst times
    Process proc[] = {{1, 0, 8}, {2, 1, 4}, {3, 2, 9}, {4, 3, 5}};
    n = sizeof(proc) / sizeof(proc[0]);

    srtf(proc);
    printProcesses(proc);

    return 0;
}

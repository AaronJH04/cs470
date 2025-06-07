#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Round Robin Scheduling
void calculateWaitingTimeAndExecutionOrder(Process proc[], int n, int quantum) {
    int remaining[n];
    for (int i = 0; i < n; i++)
        remaining[i] = proc[i].burst_time;

    int t = 0;
    printf("Execution order (RR): ");
    while (1) {
        int all_done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0 && proc[i].arrival_time <= t) {
                all_done = 0;
                int exec_time = remaining[i] > quantum ? quantum : remaining[i];
                printf("P%d ", proc[i].process_id);
                t += exec_time;
                remaining[i] -= exec_time;
                if (remaining[i] == 0) {
                    proc[i].turnaround_time = t - proc[i].arrival_time;
                    proc[i].waiting_time = proc[i].turnaround_time - proc[i].burst_time;
                }
            }
        }
        if (all_done)
            break;
    }
    printf("\n");
}

void calculateTurnaroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
}

void roundRobin(Process proc[], int n, int quantum) {
    calculateWaitingTimeAndExecutionOrder(proc, n, quantum);
    calculateTurnaroundTime(proc, n);
}

void printProcesses(Process proc[], int n) {
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].process_id, proc[i].arrival_time, proc[i].burst_time,
               proc[i].waiting_time, proc[i].turnaround_time);
    }
}

int main() {
    Process rr_proc[] = {{1, 0, 24}, {2, 0, 3}, {3, 0, 3}};
    int rr_n = sizeof(rr_proc) / sizeof(rr_proc[0]);
    int quantum = 4;

    printf("--- Round Robin (RR) ---\n");
    roundRobin(rr_proc, rr_n, quantum);
    printProcesses(rr_proc, rr_n);

    return 0;
}

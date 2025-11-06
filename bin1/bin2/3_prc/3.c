#include <stdio.h>
#include <limits.h>

struct Process {
    int id, arrival, burst, remaining, completion, turnaround, waiting;
};

// Function to calculate waiting and turnaround times for SJF (Preemptive)
void findTimesSJF(struct Process p[], int n) {
    int completed = 0, t = 0, min_burst = INT_MAX, shortest = 0, is_done = 0;
    int total_turnaround = 0, total_waiting = 0;

    while (completed != n) {
        // Find the process with the minimum remaining burst time
        int all_idle = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= t && p[i].remaining > 0 && p[i].remaining < min_burst) {
                min_burst = p[i].remaining;
                shortest = i;
                is_done = 1;
            }
        }

        if (!is_done) {
            t++;  // If no process is available at time t, increment time
            continue;
        }

        p[shortest].remaining--;  // Decrease the remaining burst time
        min_burst = p[shortest].remaining;

        if (p[shortest].remaining == 0) {
            completed++;
            is_done = 0;
            min_burst = INT_MAX;
            p[shortest].completion = t + 1;
            p[shortest].turnaround = p[shortest].completion - p[shortest].arrival;
            p[shortest].waiting = p[shortest].turnaround - p[shortest].burst;
            total_turnaround += p[shortest].turnaround;
            total_waiting += p[shortest].waiting;
        }

        t++;
    }

    // Print results for SJF
    printf("\nSJF (Preemptive) Scheduling:\n");
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].id, p[i].arrival, p[i].burst, p[i].completion, p[i].turnaround, p[i].waiting);
    }

    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround / n);
    printf("Average Waiting Time: %.2f\n", (float)total_waiting / n);
}

// Function to calculate waiting and turnaround times for Round Robin
void findTimesRR(struct Process p[], int n, int quantum) {
    int t = 0, completed = 0, total_turnaround = 0, total_waiting = 0;


    while (completed != n) {
        int all_idle = 1;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= t && p[i].remaining > 0) {
                all_idle = 0;

                if (p[i].remaining > quantum) {
                    t += quantum;
                    p[i].remaining -= quantum;
                } else {
                    t += p[i].remaining;
                    p[i].completion = t;
                    p[i].turnaround = p[i].completion - p[i].arrival;
                    p[i].waiting = p[i].turnaround - p[i].burst;
                    p[i].remaining = 0;
                    total_turnaround += p[i].turnaround;
                    total_waiting += p[i].waiting;
                    completed++;
                }
            }
        }

        if (all_idle)
            t++; // move time forward if no process available
    }


    // Print results for Round Robin
    printf("\nRound Robin Scheduling (Quantum = %d):\n", quantum);
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].id, p[i].arrival, p[i].burst, p[i].completion, p[i].turnaround, p[i].waiting);
    }

    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround / n);
    printf("Average Waiting Time: %.2f\n", (float)total_waiting / n);
}

int main() {
    int n, choice, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        p[i].id = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
        p[i].remaining = p[i].burst;  // Initially, remaining time = burst time
    }

    printf("\nChoose Scheduling Algorithm:\n");
    printf("1. SJF (Preemptive)\n2. Round Robin\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            findTimesSJF(p, n);  // Call SJF Preemptive function
            break;
        case 2:
            printf("Enter time quantum: ");
            scanf("%d", &quantum);
            findTimesRR(p, n, quantum);  // Call Round Robin function
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

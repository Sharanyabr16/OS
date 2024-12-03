#include<stdio.h>

int main() {
    int n;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Declare arrays for processes, burst times, waiting times, and turnaround times
    int p[n], bt[n], wt[n], tat[n];

    // Input burst times
    printf("Enter the burst time of %d processes: ", n);
    for (int i = 0; i < n; i++) {  // Corrected indexing
        p[i] = i + 1;  // Assign process numbers starting from 1
        scanf("%d", &bt[i]);
    }

    // Sorting processes by burst time (using Bubble Sort)
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int k = 0; k < n - i - 1; k++) {
            if (bt[k] > bt[k + 1]) {
                // Swap burst times
                temp = bt[k];
                bt[k] = bt[k + 1];
                bt[k + 1] = temp;

                // Swap process numbers
                temp = p[k];
                p[k] = p[k + 1];
                p[k + 1] = temp;
            }
        }
    }

    // Calculating waiting time
    wt[0] = 0;  // First process has zero waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculating turnaround time
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Display process details
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}

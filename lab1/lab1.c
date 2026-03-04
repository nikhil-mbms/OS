#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], tat[n], p[n];

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time for Process P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for Process P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(at[j] > at[j+1]) {
                temp = at[j]; at[j] = at[j+1]; at[j+1] = temp;
                temp = bt[j]; bt[j] = bt[j+1]; bt[j+1] = temp;
                temp = p[j]; p[j] = p[j+1]; p[j+1] = temp;
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        if(wt[i] < at[i]) wt[i] = at[i];
    }

    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

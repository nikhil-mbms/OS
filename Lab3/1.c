#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int bt[n], pr[n], ct[n], tat[n], wt[n], done[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &bt[i], &pr[i]);
        done[i] = 0;
    }

    int completed = 0, time = 0;

    while (completed < n) {
        int idx = -1, best = 1e9;

        for (int i = 0; i < n; i++) {
            if (!done[i] && pr[i] < best) {
                best = pr[i];
                idx = i;
            }
        }

        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx];
        wt[idx] = tat[idx] - bt[idx];

        done[idx] = 1;
        completed++;
    }

    float avgTAT = 0, avgWT = 0;

    printf("P\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, bt[i], pr[i], ct[i], tat[i], wt[i]);
        avgTAT += tat[i];
        avgWT += wt[i];
    }

    printf("\n%.2f\n%.2f\n", avgTAT/n, avgWT/n);

    return 0;
}

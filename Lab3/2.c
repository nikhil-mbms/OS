#include <stdio.h>

int main() {
    int n, tq;
    scanf("%d", &n);

    int bt[n], rt[n], ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    scanf("%d", &tq);

    int time = 0, completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    completed++;
                }
            }
        }
    }

    float avgTAT = 0, avgWT = 0;

    printf("P\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];

        printf("P%d\t%d\t%d\t%d\t%d\n",
               i+1, bt[i], ct[i], tat[i], wt[i]);

        avgTAT += tat[i];
        avgWT += wt[i];
    }

    printf("\n%.2f\n%.2f\n", avgTAT/n, avgWT/n);

    return 0;
}

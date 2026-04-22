#include <stdio.h>

typedef struct {
    int id;
    int period;
    int burst;
    int remaining;
    int next_deadline;
} Task;

int main() {
    int n, time = 0, hyper = 1;
    scanf("%d", &n);

    Task t[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t[i].period, &t[i].burst);
        t[i].id = i + 1;
        t[i].remaining = t[i].burst;
        t[i].next_deadline = t[i].period;
    }

    for (int i = 0; i < n; i++) {
        int a = hyper, b = t[i].period, temp;
        while (b != 0) {
            temp = b;
            b = a % b;
            a = temp;
        }
        hyper = (hyper * t[i].period) / a;
    }

    while (time < hyper) {
        int idx = -1;
        int min_period = 1e9;

        for (int i = 0; i < n; i++) {
            if (time % t[i].period == 0)
                t[i].remaining = t[i].burst;

            if (t[i].remaining > 0 && t[i].period < min_period) {
                min_period = t[i].period;
                idx = i;
            }
        }

        if (idx != -1) {
            printf("Time %d: Task %d\n", time, t[idx].id);
            t[idx].remaining--;
        } else {
            printf("Time %d: Idle\n", time);
        }

        time++;
    }

    return 0;
}
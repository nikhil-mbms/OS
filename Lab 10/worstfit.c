#include <stdio.h>

int main() {
    int b[20], p[20], a[20], m, n, i, j, x;

    printf("Enter no of blocks: ");
    scanf("%d", &m);

    printf("Enter block sizes:\n");
    i = 0;
    while (i < m) {
        scanf("%d", &b[i]);
        i++;
    }

    printf("Enter no of processes: ");
    scanf("%d", &n);

    printf("Enter process sizes:\n");
    i = 0;
    while (i < n) {
        scanf("%d", &p[i]);
        a[i] = -1;
        i++;
    }

    i = 0;
    while (i < n) {
        x = -1;
        j = 0;
        while (j < m) {
            if (b[j] >= p[i]) {
                if (x == -1 || b[j] > b[x])
                    x = j;
            }
            j++;
        }

        if (x != -1) {
            a[i] = x;
            b[x] -= p[i];
        }

        i++;
    }

    printf("PNo\tPSize\tBlock\n");
    i = 0;
    while (i < n) {
        if (a[i] != -1)
            printf("%d\t%d\t%d\n", i + 1, p[i], a[i] + 1);
        else
            printf("%d\t%d\tNot Allocated\n", i + 1, p[i]);
        i++;
    }

    return 0;
}

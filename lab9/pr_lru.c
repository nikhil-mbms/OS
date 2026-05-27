#include <stdio.h>

int main() {
    int n, f, i, j, p[50], fr[10], t[10], pf = 0, c = 0;
    int h, l, mn;

    printf("Enter no. of pages: ");
    scanf("%d", &n);

    printf("Enter page string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter no. of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        fr[i] = -1;
        t[i] = 0;
    }

    for(i = 0; i < n; i++) {
        h = 0;

        for(j = 0; j < f; j++) {
            if(fr[j] == p[i]) {
                c++;
                t[j] = c;
                h = 1;
                break;
            }
        }

        if(!h) {
            mn = t[0];
            l = 0;

            for(j = 1; j < f; j++) {
                if(t[j] < mn) {
                    mn = t[j];
                    l = j;
                }
            }

            c++;
            fr[l] = p[i];
            t[l] = c;
            pf++;
        }

        printf("\n");
        for(j = 0; j < f; j++)
            printf("%d\t", fr[j]);
    }

    printf("\nPage Faults = %d", pf);

    return 0;
}
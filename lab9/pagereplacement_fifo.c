#include <stdio.h>

int main() {
    int n, f, i, j, p[50], fr[10], k = 0, pf = 0, h;

    printf("Enter no. of pages: ");
    scanf("%d", &n);

    printf("Enter page string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter no. of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        fr[i] = -1;

    for(i = 0; i < n; i++) {
        h = 0;

        for(j = 0; j < f; j++) {
            if(fr[j] == p[i]) {
                h = 1;
                break;
            }
        }

        if(!h) {
            fr[k] = p[i];
            k = (k + 1) % f;
            pf++;
        }

        printf("\n");
        for(j = 0; j < f; j++)
            printf("%d\t", fr[j]);
    }

    printf("\nPage Faults = %d", pf);

    return 0;
}
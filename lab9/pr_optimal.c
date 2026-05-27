#include <stdio.h>

int main() {
    int n, f, i, j, k, p[50], fr[10], pf = 0;
    int h, far, pos, idx;

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
            far = -1;
            pos = -1;

            for(j = 0; j < f; j++) {
                idx = -1;

                for(k = i + 1; k < n; k++) {
                    if(fr[j] == p[k]) {
                        idx = k;
                        break;
                    }
                }

                if(idx == -1) {
                    pos = j;
                    break;
                }

                if(idx > far) {
                    far = idx;
                    pos = j;
                }
            }

            fr[pos] = p[i];
            pf++;
        }

        printf("\n");
        for(j = 0; j < f; j++)
            printf("%d\t", fr[j]);
    }

    printf("\nPage Faults = %d", pf);

    return 0;
}
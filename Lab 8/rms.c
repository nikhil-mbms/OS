#include <stdio.h>
#include <math.h>

typedef struct {
    int id;
    float c, t, u;
} T;

int main() {
    int n;
    float U = 0.0, b = 0.0;

    printf("--- RMS ---\n");
    printf("Enter tasks: ");
    scanf("%d", &n);

    T a[n];

    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
        printf("\nTask P%d:\n", a[i].id);

        printf("Ci: ");
        scanf("%f", &a[i].c);

        printf("Ti: ");
        scanf("%f", &a[i].t);

        a[i].u = a[i].c / a[i].t;
        U += a[i].u;
    }

    b = n * (pow(2.0, 1.0 / n) - 1.0);

    printf("\nU: %.4f\n", U);
    printf("Bound: %.4f\n", b);

    if (U <= b)
        printf("SCHEDULABLE\n");
    else if (U <= 1.0)
        printf("MAY BE SCHEDULABLE\n");
    else
        printf("NOT SCHEDULABLE\n");

    return 0;
}
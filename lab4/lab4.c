#include <stdio.h>

#define M 50

void calc(int bt[], int wt[], int tat[], int n) {
    wt[0] = 0;
    tat[0] = bt[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }
}

void show(int bt[], int wt[], int tat[], int id[], int n, char name[]) {
    float tw = 0, tt = 0;

    printf("\n--- %s Queue ---\n", name);
    printf("ID\tAT\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t0\t%d\t%d\t%d\n", id[i], bt[i], wt[i], tat[i]);
        tw += wt[i];
        tt += tat[i];
    }

    printf("Avg WT = %.2f\n", tw / n);
    printf("Avg TAT = %.2f\n", tt / n);
}

int main() {
    int bt1[M], wt1[M], tat1[M], id1[M];
    int bt2[M], wt2[M], tat2[M], id2[M];
    int ns, nu;

    printf("Enter number of SYSTEM processes: ");
    scanf("%d", &ns);

    for (int i = 0; i < ns; i++) {
        id1[i] = i + 1;
        printf("Enter BT for System %d: ", i + 1);
        scanf("%d", &bt1[i]);
    }

    printf("\nEnter number of USER processes: ");
    scanf("%d", &nu);

    for (int i = 0; i < nu; i++) {
        id2[i] = i + 1;
        printf("Enter BT for User %d: ", i + 1);
        scanf("%d", &bt2[i]);
    }

  
    calc(bt1, wt1, tat1, ns);

 
    int offset = 0;
    if (ns > 0)
        offset = wt1[ns - 1] + bt1[ns - 1];

  
    calc(bt2, wt2, tat2, nu);

   
    for (int i = 0; i < nu; i++) {
        wt2[i] += offset;
        tat2[i] += offset;
    }

 
    show(bt1, wt1, tat1, id1, ns, "System");
    show(bt2, wt2, tat2, id2, nu, "User");

    return 0;
}

#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of processes : \n");
    scanf("%d",&n);
    int p[n],wt[n],tat[n],bt[n];

    printf("Enter the burst Time : \n");
    for(int i = 0;i<n;i++){
        scanf("%d",&bt[i]);
        p[i] = i+1;
    }
    int t;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int flag = 0;
            if(bt[j]<bt[i]){
                t = bt[j];bt[j] = bt[i];bt[i] = t; t = p[j];p[j] = p[i];p[i] = t;flag = 1;
            }
            if(!flag) break;
        }
    }

    wt[0] = 0;

    for(int i = 1;i<n;i++){
        wt[i] = wt[i-1]+bt[i-1];
    }
    for(int i = 0;i<n;i++)

    {
        tat[i] = wt[i]+bt[i];
    }

    float avg_wt = 0;
    float avg_tat = 0;

    for(int i = 0;i<n;i++){
        avg_wt+=wt[i];
        avg_tat+=tat[i];
    }

    avg_wt = avg_wt/n;
    avg_tat = avg_tat/n;

    printf("\nProcess\tBT\tWT\tTAT\n");
    
    for(int i = 0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }

    printf("Avg WT : %.2f",avg_wt);
    printf("Avg TAT : %.2f",avg_tat);

    return 0;
}
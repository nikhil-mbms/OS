#include <stdio.h>

int main() {
    int n, m, i, j, k;

    scanf("%d%d", &n, &m);

    int a[n][m], mx[n][m], ne[n][m];
    int av[m], f[n], ans[n];

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&mx[i][j]);

    for(i=0;i<m;i++)
        scanf("%d",&av[i]);

    for(i=0;i<n;i++) {
        f[i]=0;
        for(j=0;j<m;j++)
            ne[i][j]=mx[i][j]-a[i][j];
    }

    int c=0;

    for(k=0;k<n;k++) {
        for(i=0;i<n;i++) {
            if(f[i]==0) {
                int ok=1;

                for(j=0;j<m;j++) {
                    if(ne[i][j]>av[j]) {
                        ok=0;
                        break;
                    }
                }

                if(ok) {
                    ans[c++]=i;

                    for(j=0;j<m;j++)
                        av[j]+=a[i][j];

                    f[i]=1;
                }
            }
        }
    }

    if(c==n) {
        printf("Safe\n");
        for(i=0;i<n;i++)
            printf("P%d ",ans[i]);
    }
    else {
        printf("Unsafe");
    }

    return 0;
}
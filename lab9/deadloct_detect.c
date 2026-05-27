#include <stdio.h>

int main() {
    int n,m,i,j,k;

    scanf("%d%d",&n,&m);

    int a[n][m],r[n][m],av[m];
    int f[n],ans[n];

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&r[i][j]);

    for(i=0;i<m;i++)
        scanf("%d",&av[i]);

    for(i=0;i<n;i++)
        f[i]=0;

    int c=0;

    for(k=0;k<n;k++) {
        for(i=0;i<n;i++) {
            if(f[i]==0) {
                int ok=1;

                for(j=0;j<m;j++) {
                    if(r[i][j]>av[j]) {
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
        printf("No Deadlock\n");
    }
    else {
        printf("Deadlock\n");
    }

    return 0;
}
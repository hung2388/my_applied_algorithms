#include <stdio.h>
#include <stdlib.h>
#define max 500000
int a;
int b;

int main()
{
    scanf("%d %d", &a, &b);
    unsigned long long A[a][b];
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {    
        int r1,r2,c1,c2;
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        int sum=0;
        for(int i=r1-1;i<=r2-1;i++)
        {
            for(int j=c1-1;j<=c2-1;j++)
            {
                sum+=A[i][j];
            }
        }
        printf("%d\n",sum);
    }
}

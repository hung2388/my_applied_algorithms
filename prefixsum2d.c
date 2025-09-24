#include <stdio.h>
#include <stdlib.h>
#define max 10000
int A[max][max];
int P[max][max];
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            P[i][j]=A[i][j]+P[i-1][j]+P[i][j-1]-P[i-1][j-1];
        }
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int c1,r1,c2,r2;
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        int sum=P[r2][c2]-P[r2][c1-1]-P[r1-1][c2]+P[r1-1][c1-1];
        printf("%d\n",sum);
    }
}

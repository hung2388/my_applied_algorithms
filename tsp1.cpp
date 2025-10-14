#include <bits/stdc++.h>
using namespace std;
int n;
int A[30][30];
int x[30];
bool visited[30];
int cmin=INT_MAX;
int f=0;
int fee_min=INT_MAX;
void update()
{
    int total=f+A[x[n]][x[1]];
    if(total<fee_min) fee_min=total;
}
void Try(int k)
{
    for(int v=2;v<=n;v++)
    {
        if(!visited[v])
        {
        f+=A[x[k-1]][v];
        x[k]=v;
        visited[v]=true;
        if(k==n)
        {
            update();
        }
        else
        {
            int g=f+cmin*(n-k+1);
            if(g<fee_min) Try(k+1);
        }
        visited[v]=false;
        f-=A[x[k-1]][v];
        }
    
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>A[i][j];
            if(i!=j) cmin=min(cmin,A[i][j]);
        }
    }
    x[1]=1; visited[1]=true;
    Try(2);
    cout<<fee_min<<endl;
}

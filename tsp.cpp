#include <bits/stdc++.h>
using namespace std;
int n;
int a[30][30];
int cmin=INT_MAX;
int f_min=INT_MAX;
int fee=0;
bool visited[30];
int x[30];

void updatebest()
{
    int total=fee+a[x[n]][x[1]];
    if(total<f_min)
        f_min=total;
}

void tryy (int k)
{
    for(int v=2;v<=n;v++)
    {
        if(!visited[v])
        {
            x[k]=v;
            fee+=a[x[k-1]][v];
            visited[v]=true;
        if(k==n)
        {
            updatebest();
        }
        else
        {
            int g=fee+cmin*(n-k+1);
            if(g<f_min) tryy(k+1);
        }
            fee-=a[x[k-1]][v];
            visited[v]=false;
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
            cin>>a[i][j];
            if(i!=j) cmin=min(cmin,a[i][j]);
        }
    }
    x[1]=1; visited[1]=true;
    tryy(2);
    cout<<f_min<<endl;
}

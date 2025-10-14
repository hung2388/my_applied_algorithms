#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[60][60];
int cmin=INT_MAX;
int feemin=INT_MAX;
int f=0;
int x[60];
bool visited[60];
int load=0;

bool check(int v)
{
    if(visited[v]==true) return false;
    if(v>n)
    {
        if(visited[v - n]==false) return false;
    }
    else
    {
        if(load+1>k) return false;
    }
    return true;
}
void update()
{
    if(f+a[x[2*n]][0]<feemin)
    feemin=f+a[x[2*n]][0];
}
void Try(int k)
{
    for(int v=1;v<=2*n;v++)
    {
        if(check(v))
        {
            visited[v]=true;
            x[k]=v;
            f+=a[x[k-1]][v];
            if(v<=n) load++; else load--;
            if(k==2*n)
            {
                update();
            }
            else
            {
                int g=f+cmin*(2*n-k+1);
                if(g<feemin) Try(k+1);
            }
            visited[v]=false;
            f-=a[x[k-1]][v];
            if(v<=n) load--; else load++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<=2*n;i++)
    {
        for(int j=0;j<=2*n;j++)
        {
            cin>>a[i][j];
            if(i!=j)
            cmin=min(cmin,a[i][j]);
        }
    }
    x[1]=0;
    visited[0]=true;
    Try(1);
    cout<<feemin<<endl;
}

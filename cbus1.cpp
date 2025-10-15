#include <bits/stdc++.h>
using namespace std;
int customer,chair;
int dis[30][30];
int route[30];
bool visited[30];
int fee=0;
int ans=INT_MAX;
int minfeetravel=INT_MAX;
int load=0;
bool check(int k)
{
    if(visited[k]==true) return false;
    if(k>customer)
    {
        if(visited[k-customer]==false) return false;
    }
    else
    {
        if(load+1>chair) return false;
    }
    return true;
}

void updatebest()
{
    if(fee+dis[route[2*customer]][0]<ans) ans=fee+dis[route[2*customer]][0];
}

void Try(int k)
{
    for(int v=1;v<=2*customer;v++)
    {
        if(check(v))
        {
            route[k]=v;
            visited[v]=true;
            fee+=dis[route[k-1]][v];
            if(v>customer) load--; else load++;
            if (k==2*customer)
            {
                updatebest();
            }
            else
            {
                if(fee+(2*customer-k+1)*minfeetravel>ans) return;
                else
                {
                    Try(k+1);
                }
            }
            visited[v]=false;
            fee-=dis[route[k-1]][v];
            if(v>customer) load++; else load--;
        }
    }
}



int main()
{
    cin>>customer>>chair;
    for(int i=0;i<=2*customer;i++)
    {
        for(int j=0;j<=2*customer;j++)
        {
            cin>>dis[i][j];
            minfeetravel=min(minfeetravel,dis[i][j]);
        }
    }
    route[0]=0; visited[0]=true;
    Try(1);
    cout<<ans<<endl;
}

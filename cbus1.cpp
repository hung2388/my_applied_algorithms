#include <bits/stdc++.h>
using namespace std;
int customer,chair;
int A[30][30];
bool visited[30];
int route[30];
int minspace=INT_MAX;
int fee=0;
int min_fee=INT_MAX;
int load=0;
bool check(int k)
{
    if(visited[k]==true) return true;
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
    if(fee+A[route[2*customer]][0]<min_fee) min_fee=fee+A[route[2*customer]][0];
}
void Try(int k)
{
    for(int i=1;i<=2*customer;i++)
    {
        if(check(i))
        {
            route[k]=i;
            visited[i]=true;
            fee+=A[route[k-1]][i];
            if(k>customer) load--; else load++;
            if(k==2*customer) updatebest();
            else
            {
                if(fee+minspace*(customer-k+1)<min_fee) Try(k+1);
            }
            visited[i]=false;
            fee-=A[route[k-1]][i];
            if(k>customer) load++; else load--;
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
            cin>>A[i][j];
            minspace=min(minspace,A[i][j]);
        }
    }
    route[0]=0; visited[0]=1;
    Try(1);
    cout<<min_fee;
}
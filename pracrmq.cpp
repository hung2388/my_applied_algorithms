#include <bits/stdc++.h>
using namespace std;
const int maxx=1000000;
int A[maxx],m,n,ST[maxx][50];
void build()
{
    for(int i=0;i<n;i++)
    {
        ST[i][0]=A[i];
    }
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=0;i+(1<<j)<=n;i++)
        {
            if(ST[i][j-1]<ST[i+(1<<(j-1))][j-1])
            ST[i][j]=ST[i][j-1];
            else ST[i][j]=ST[i+(1<<(j-1))][j-1];
        }
    }
}
int rmq(int l, int r)
{
    int k=log2(r-l+1);
    return min(ST[l][k],ST[r-(1<<k)+1][k]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    build();
    cin>>m;
    int sum=0;
    int x,y;
    while(m--)
    {
        cin>>x>>y;
        sum+=rmq(x,y);
    }
    cout<<sum<<endl;
}

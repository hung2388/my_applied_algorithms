#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int Q; cin>>Q;
    int res=0,S=0;
    int i=1;
    int* A=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int j=1;j<=n;j++)
    {
        S=S+A[j];
        while(i<=j&&S>Q)
        {
            S=S-A[i];
            i=i+1;
        }
        res=max(res,j-i+1);
    }
    cout<<res<<endl;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    int res=0;
    int Sum=0;
    cin>>n>>q;
    vector <int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int j=0;
    for(int i=0;i<n;i++)
    {
        Sum+=A[i];
        while(j<=i&&Sum>q)
        {
            Sum-=A[j];
            j++;
        }
        res=max(res,i-j+1);
    }
    cout<<res<<endl;
}

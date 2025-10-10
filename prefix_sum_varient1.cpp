#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin>>n;
    int k; cin>>k;
    vector <int> energy(n);
    for(int i=0;i<n;i++) cin>>energy[i];
    int maxi=INT_MIN;
    vector <int> prefix_sum(n);
    for(int i=n;i>=0;i--)
    {
        if(i+k>=n)
        prefix_sum[i]=energy[i];
        else
        prefix_sum[i]=energy[i]+prefix_sum[i+k];
        maxi=max(maxi,prefix_sum[i]);
    }
    cout<<maxi<<endl;
}
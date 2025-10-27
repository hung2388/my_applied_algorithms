#include <bits/stdc++.h>
using namespace std;
bool comp(auto &a,auto &b)
{
    return a>b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector <pair<int,int>> segment(n);
    for(int i=0;i<n;i++)
    {
        cin>>segment[i].first>>segment[i].second;
    }
     sort(segment.begin(),segment.end(),[](auto &a,auto &b)
     {
         return a.second<b.second;
     });
     int ans=0;
     int lastmax=INT_MIN;
     for(int i=0;i<n;i++)
     {
        if(segment[i].first>lastmax)
        {
            lastmax=segment[i].second;
            ans++;
        }
     }
     cout<<ans<<endl;

}

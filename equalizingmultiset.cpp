#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        unordered_map<long long,int> c;
        int a,b;
        cin>>a>>b;
        long long x;
        for(int i=0;i<a;i++)
        {
            cin>>x;
            c[x]++;
        }
        for(int i=0;i<b;i++)
        {
            cin>>x;
            c[x]--;
        }
        int ans=0;
        for(auto& p:c) ans+=abs(p.second);
        cout<<ans<<endl;

    }

}

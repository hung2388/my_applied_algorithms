#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_set <int> a;
    int n,q;
    cin>>n>>q;
    int count=0;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        if(a.find(q-tmp)==a.end())
        a.insert(tmp);
        else count++;
    }
    cout<<count<<flush;
}
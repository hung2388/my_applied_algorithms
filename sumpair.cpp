#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;int Q;
    cin>>n>>Q;
    unordered_set <int> check;
    int tmp;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        if(check.find(Q-tmp)==check.end())
        check.insert(tmp);
        else cnt++;
    }
    cout<<cnt<<endl;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,tong;
    cin>>n>>tong;
    vector <long long> A(n); 
    unordered_set <long long> P;
    int need,count=0;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        need=tong-A[i];
        if(P.find(need)!=P.end()) count++;
        P.insert(A[i]);
    }
    cout<<count;
}
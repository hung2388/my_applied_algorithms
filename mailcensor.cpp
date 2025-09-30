#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        string s;
        cin>>s;
        int k=s.find("@");
        for(int i=1;i<=k-2;i++)
        {
            s[i]='*';
        }
        cout<<s<<endl;
    }
}

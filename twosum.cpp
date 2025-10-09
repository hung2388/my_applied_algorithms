#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    vector <int> nums;
    unordered_map <int,int> AnsIdx;
    int need;
    cin>>n>>q;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        nums.push_back(x);
        need=q-x;
        if(AnsIdx.count(need))
        {
            cout<<"["<<AnsIdx[need]<<","<<i<<"]"<<endl;
        }
        else
        AnsIdx[nums[i]]=i;
    }
}

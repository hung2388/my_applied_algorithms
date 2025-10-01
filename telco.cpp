#include <bits/stdc++.h>
using namespace std;
bool check(string s)
{
    if(s.length()!=10) return false;
    int a=0;
    while (1)
    {
        if(a==10) break;
        if(s[a]<'0'||s[a]>'9')
        {
            return false;
        }
        a++;
    }
    return true;
}
int timecheck(string st, string et)
{
    int time;
    int start=((st[0]-'0')*10+(st[1]-'0'))*3600+((st[3]-'0')*10+(st[4]-'0'))*60 +(st[6]-'0')*10+(st[7]-'0');
    int end=((et[0]-'0')*10+(et[1]-'0'))*3600+((et[3]-'0')*10+(et[4]-'0'))*60 +(et[6]-'0')*10+(et[7]-'0');
    return time=end-start;
}
int main()
{
    map<string,int> numcalla, timecall;
    int numcall=0;
    string s;
    string calln,revn,trash,start,end;
    int truem;
    while(cin>>s)
    {

        if(s=="#")
        break;
        if(s=="call")
        {
            cin>>calln>>revn>>trash>>start>>end;
            if(!check(calln)||!check(revn))
            {
                truem=0;
            }
            else truem=1;
            numcall++;
            numcalla[calln] ++;
            timecall[calln] +=timecheck(start,end);
        }
    }
    string queryy;
    while(cin>>queryy)
    {

        if(queryy=="#") break;
        else
        if(queryy=="?check_phone_number")
        {
            cout<<truem<<endl;
        }
        else if(queryy=="?number_calls_from")
        {
            string z;
            cin>>z;
            cout<<numcalla[z]<<endl;
        }
        else if(queryy=="?number_total_calls")
        {
            cout<<numcall<<endl;
        }
        else if(queryy=="?count_time_calls_from")
        {
            string z;
            cin>>z;
            cout<<timecall[z]<<endl;
        }

    }
}
 
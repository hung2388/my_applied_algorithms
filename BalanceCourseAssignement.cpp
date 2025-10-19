#include <bits/stdc++.h>
using namespace std;
const int maxc=1e6;
int teacher, subject;
vector <int> teacherload;
vector <vector<bool>> TeacherCanTeach;
vector <int> Sol;
bool conflict[maxc][maxc];
int MaxiCourse=0;
int MinimunMaxCourse=0;


void solution()
{
        if(MaxiCourse<MinimunMaxCourse) MinimunMaxCourse=MaxiCourse;
}
bool check(int t, int s)
{
    if(TeacherCanTeach[t][s]==false) return false;
    for(int i=1;i<=subject;i++)
    if(Sol[i]=t&&conflict[i][s]==true) return false;
    return true;
}

void Try(int k)
{
    if(k>subject)
    {
        solution;
        return;
    }
    bool prof=false;
    for(int i=0;i<teacher;i++)
    {
        if(TeacherCanTeach[i][k]==true)
        prof=true; break;
    }
    if(prof==false) 
    {
        MinimunMaxCourse=-1;
        return;
    }
    for(int i=0;i<teacher;i++)
    {
        if(check(i,k))
        {
            Sol[k]=i;
            teacherload[i]++;
            int PreviousMaxcourse=MaxiCourse;
            MaxiCourse=max(MaxiCourse,teacherload[i]);
            if(MaxiCourse<MinimunMaxCourse)
            {
                Try(k+1);
            }
            teacherload[i]--;
            MaxiCourse=PreviousMaxcourse;
        }
    }
}



int main()
{
    cin>>teacher>>subject;
    int a;
    int b;
 //   teacherload.assign(teacher+1,{0});
    TeacherCanTeach.assign(teacher+1,vector <bool> (subject+1,false));
    for(int i=0;i<teacher;i++)
    {
        cin>>a;
        for(int j=0;j<a;j++)
        {
            cin>>b;
            TeacherCanTeach[i][b]=true;
        }
    }
    cin>>a;
    int b,c;
    for(int j=0;j<a;j++)
    {
        cin>>b>>c;
        conflict[b][c]=true;
        conflict[c][b]=true;
    }
    Try(1);
}
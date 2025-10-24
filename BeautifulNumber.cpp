class Solution {
public:
    long long findnum(long long target,long long currentnumber,long long remaining, vector <long long> digits)
    {
        if(remaining==0)
        {
            if (currentnumber>target)
            {
                for(int i=1;i<=9;i++)
                {
                    if(digits[i]>0&&digits[i]!=i)
                    return 0;
                }
                    return currentnumber;
            }
            return 0;
        }
        long long result=0;
        for(int i=1;i<=9&&result==0;i++)
        {
            if(digits[i]<i&&(i-digits[i])<=remaining)
            {
                digits[i]++;
                result=findnum(target,currentnumber*10+i,remaining-1,digits);
                digits[i]--;
            }
        }
        return result;
    }
    int nextBeautifulNumber(int n) {
        string s=to_string(n);
        int length=s.size();
        vector <long long> digit(10,0);
        long long res= findnum(n,0,length,digit);
        digit.assign(10,0);
        long long moreres=findnum(n,0,length+1,digit); 
        if(res==0) return moreres;
        else return res;
    }
};
class Solution {
public:
    int totalMoney(int n) {
        int sum=0;
        int k=n/7;
        int nthweekfirstday=1;
        for(int i=0;i<k;i++)
        {
            int b=nthweekfirstday;
            for(int i=0;i<7;i++)
            {
                sum+=b;
                b++;
            }
            nthweekfirstday++;
        }
        for(int i=0;i<n-7*k;i++)
            {
                sum+=nthweekfirstday;
                nthweekfirstday++;
            }
        return sum;
    }
};
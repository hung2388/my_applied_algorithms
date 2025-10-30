class Solution {
public:
    int mininrange[100000][30];
    int n;
    vector<int> copycat;

    int minNumberOperations(vector<int>& target) {
        n = target.size();
        copycat = target;
        build();
        return solve(0,n-1,0);
    }
    int solve(int l, int r,int base)
    {
        if(l>r) return 0;
        int m=rmq(l,r);
        int val=copycat[m];
        int cost=val-base;
        return cost+solve(l,m-1,val)+solve(m+1,r,val);
    }

    int rmq(int i, int j) {
        int k = log2(j - i + 1);
        int a=mininrange[i][k];
        int b=mininrange[j-(1<<k)+1][k];
        return (copycat[a]<copycat[b])?a:b;
    }

    void build() {
        for (int i = 0; i < n; i++) {
            mininrange[i][0] = i;
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                if (copycat[mininrange[i][j - 1]] <
                    copycat[mininrange[i + (1 << (j - 1))][j - 1]])
                    mininrange[i][j] = mininrange[i][j - 1];
                else
                    mininrange[i][j] = mininrange[i + (1 << (j - 1))][j - 1];
            }
        }
    }
};
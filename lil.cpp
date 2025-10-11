#include <bits/stdc++.h>
using namespace std;

long long maxDamage(vector<int>& power) {
    unordered_map<int, long long> sum;
    for (int x : power) sum[x] += x; 

    vector<int> keys;
    for (auto& p : sum) keys.push_back(p.first);
    sort(keys.begin(), keys.end());

    int n = keys.size();
    vector<long long> dp(n);

    dp[0] = sum[keys[0]];
    for (int i = 1; i < n; i++) {
        long long take = sum[keys[i]];
        if (keys[i] - keys[i - 1] < 3) {
            take += (i >= 2 ? dp[i - 2] : 0);
            dp[i] = max(dp[i - 1], take);
        } else {
            dp[i] = dp[i - 1] + take;
        }
    }
    return dp[n - 1];
}

int main() {
    vector<int> power = {1,1,3,4};
    cout << maxDamage(power); // Output: 6
}

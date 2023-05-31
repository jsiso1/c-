class Solution {

long long MOD = (1e9+7);
vector<vector<long long>> dp;
public:



    int pow(int n, int p) {
        long long ans = 1;
        long long x = n;

        while (p) {
            if ((p&1) == 1)
                ans = (ans*x)%MOD;
            p = p>>1;
            x = (x*x)%MOD;
        }
        return ans;

    }
    int mul(int a, int b) { return (long long)a * b % m; }

    int numberOfWays(int n) {

        vector<int> inv(n + 2);
        inv[1] = 1;
        for (int i = 2; i < n + 2; i++) {
            int k = MOD / i, r = MOD % i;
            inv[i] = MOD - mul(k, inv[r]);
        }

        n /= 2;
        dp = vector<vector<long long>> (2*n+1, vector<long long>(2*n+1, 1));
        combinations(2*n);
        int inverse = inv[n+1];
        return dp[2*n][n]*inverse%MOD;
    }

    void combinations(int n) {
        for (int i = 1; i<=n; i++)
            dp[i][i] = 1;

        for (int i=1; i<=n; i++)
            for (int j=1; j<i; j++) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
                if (dp[i][j] > MOD)
                    dp[i][j] -= MOD;
            }

    }


};

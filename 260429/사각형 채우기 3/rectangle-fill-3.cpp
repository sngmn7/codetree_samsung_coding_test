#include <iostream>
#include <vector>

using namespace std;

long long dp[1001];
long long MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 2;

    long long sum = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 3) % MOD;

        if (i >= 3) {
            sum = (sum + dp[i - 3]) % MOD;
        }
        dp[i] = (dp[i] + sum * 2) % MOD;
    }

    cout << dp[n] << "\n";

    return 0;
}
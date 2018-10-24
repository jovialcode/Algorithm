#include<cstdio>
int n,dp[1001],a[1001];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        int maxi = 0, mini = 1e4;
        for (int j = i; j; j--) {
            if (a[j] > maxi) maxi = a[j];
            if (a[j] < mini) mini = a[j];
            if (dp[i] < dp[j - 1] + maxi - mini) dp[i] = dp[j - 1] + maxi - mini;
        }
    }
    printf("%d", dp[n]);
    return 0;
}

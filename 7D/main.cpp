// copy from https://blog.51cto.com/u_15303184/3109078

#include <stdio.h>
#include <string.h>

const int maxn = 1e7 + 5;
char s[maxn];
int dp[maxn];
long long p1 = 131, t1 = 1;
long long p2 = 127, t2 = 1;
long long h1 = 0, rh1 = 0;
long long h2 = 0, rh2 = 0;
int main()
{
    scanf("%s", s + 1);
    long long ans = 0;
    int l = strlen(s + 1);
    for (int i = 1; i <= l; i++)
    {
        h1 = h1 * p1 + s[i];
        rh1 = s[i] * t1 + rh1;
        t1 = t1 * p1;

        h2 = h2 * p2 + s[i];
        rh2 = s[i] * t2 + rh2;
        t2 = t2 * p2;
        if (h1 == rh1 && h2 == rh2)
        {
            dp[i] = dp[i / 2] + 1;
        }
        ans += dp[i];
    }
    printf("%lld", ans);
}

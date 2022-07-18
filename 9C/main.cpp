#include <iostream>

bool FindAns(int n, int &ans)
{
    if (0 == n)
    {
        return 0;
    }

    if (FindAns(n / 10, ans))
    {
        ans = (ans << 1) + 1;
        return true;
    }

    ans <<= 1;
    if (n % 10 >= 1)
    {
        ans += 1;
    }
    return (n % 10 > 1);
}

int main()
{
    int n;
    std::cin >> n;

    int ans = 0;
    FindAns(n, ans);
    std::cout << ans;
    return 0;
}

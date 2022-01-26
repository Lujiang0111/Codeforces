#include <stdint.h>

#include <iostream>

bool Solve(int64_t a, int64_t b, int64_t c, int64_t &ans_x, int64_t &ans_y)
{
    if (0 == a)
    {
        if (0 == -c % b)
        {
            ans_x = 0;
            ans_y = -c / b;
            return true;
        }

        return false;
    }

    if (0 == b)
    {
        if (0 == -c % a)
        {
            ans_x = -c / a;
            ans_y = 0;
            return true;
        }

        return false;
    }

    if (b < 0)
    {
        if (!Solve(a, b + ((-b / a) + 1) * a, c, ans_x, ans_y))
        {
            return false;
        }

        ans_x = (-c - b * ans_y) / a;
        return true;
    }

    if (a < b)
    {
        if (!Solve(a, b % a, c, ans_x, ans_y))
        {
            return false;
        }

        ans_x = (-c - b * ans_y) / a;
        ans_y += (ans_x / b) * a;
        ans_x %= b;
        return true;
    }

    if (!Solve(a % b, b, c, ans_x, ans_y))
    {
        return false;
    }

    ans_y = (-c - a * ans_x) / b;
    ans_x += (ans_y / a) * b;
    ans_y %= a;
    return true;
}

int main(int argc, char **argv)
{
    int64_t a = 0;
    int64_t b = 0;
    int64_t c = 0;
    std::cin >> a >> b >> c;

    if (a < 0)
    {
        a = -a;
        b = -b;
        c = -c;
    }

    int64_t ans_x = 0;
    int64_t ans_y = 0;
    if (!Solve(a, b, c, ans_x, ans_y))
    {
        std::cout << -1;
        return 0;
    }

    std::cout << ans_x << " " << ans_y;
    return 0;
}

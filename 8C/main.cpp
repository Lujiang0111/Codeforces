#include <vector>
#include <iostream>

struct Point
{
    int x;
    int y;
    int mask;
};

struct Dp
{
    int dis;
    int front_objs[2];
};

void FindPath(const std::vector<Dp> &dp, const std::vector<Point> &objs, int state)
{
    if (state == 0)
    {
        std::cout << 0;
        return;
    }

    if (dp[state].front_objs[0] == dp[state].front_objs[1])
    {
        FindPath(dp, objs, state - objs[dp[state].front_objs[0]].mask);
        std::cout << " " << dp[state].front_objs[0] + 1 << " " << 0;
    }
    else
    {
        FindPath(dp, objs, state - objs[dp[state].front_objs[0]].mask - objs[dp[state].front_objs[1]].mask);
        std::cout << " " << dp[state].front_objs[0] + 1 << " " << dp[state].front_objs[1] + 1 << " " << 0;
    }
}

int main()
{
    int start_x = 0;
    int start_y = 0;
    std::cin >> start_x >> start_y;

    int n = 0;
    std::cin >> n;
    std::vector<Point> objs(n);

    std::vector<std::vector<int>> dis(n);
    for (auto &&x : dis)
    {
        x.assign(n, 0);
    }

    for (int i = 0; i < n; ++i)
    {
        objs[i].mask = (i > 0) ? (objs[i - 1].mask << 1) : 1;
        std::cin >> objs[i].x >> objs[i].y;
        for (int j = 0; j <= i; ++j)
        {
            dis[j][i] = (objs[j].x - start_x) * (objs[j].x - start_x) + (objs[j].y - start_y) * (objs[j].y - start_y) +
                (objs[i].x - objs[j].x) * (objs[i].x - objs[j].x) + (objs[i].y - objs[j].y) * (objs[i].y - objs[j].y) +
                (start_x - objs[i].x) * (start_x - objs[i].x) + (start_y - objs[i].y) * (start_y - objs[i].y);
        }
    }

    int state_size = 1 << n;
    std::vector<Dp> dp(state_size);
    
    dp[0].dis = 0;
    for (int state = 1; state < state_size; ++state)
    {
        dp[state].dis = -1;
        for (int i = 0; i < n; ++i)
        {
            if (state & objs[i].mask)
            {
                for (int j = i; j < n; ++j)
                {
                    if (state & objs[j].mask)
                    {
                        int front_state = (i == j) ? (state - objs[i].mask) : (state - objs[i].mask - objs[j].mask);
                        if ((dp[state].dis < 0) || (dp[front_state].dis + dis[i][j] < dp[state].dis))
                        {
                            dp[state].dis = dp[front_state].dis + dis[i][j];
                            dp[state].front_objs[0] = i;
                            dp[state].front_objs[1] = j;
                        }
                    }
                }

                // 剪枝，没有这个会TLE
                break;
            }
        }
    }

    std::cout << dp[state_size - 1].dis << std::endl;
    FindPath(dp, objs, state_size - 1);
    return 0;
}

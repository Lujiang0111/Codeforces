#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>

static int64_t GetHashCode(int64_t x, int64_t y)
{
    return x * std::numeric_limits<int>::max() + y;
}

static void NewPoint(std::unordered_map<int64_t, bool> &map_hash, int64_t x, int64_t y)
{
    int64_t hash_code = GetHashCode(x, y);
    map_hash.emplace(hash_code, true);
}

static bool IsPointExsit(const std::unordered_map<int64_t, bool> &map_hash, int64_t x, int64_t y)
{
    int64_t hash_code = GetHashCode(x, y);
    return (map_hash.end() != map_hash.find(hash_code));
}

int main(int argc, char **argv)
{
    constexpr struct Step
    {
        char ch;
        int64_t x_offset;
        int64_t y_offset;
    }kStep[] =
    {
        {'L', -1, 0},
        {'R', 1, 0},
        {'U', 0, -1},
        {'D', 0 ,1},
    };
    constexpr int64_t kStepSize = sizeof(kStep) / sizeof(kStep[0]);

    std::unordered_map<int64_t, bool> map_hash;
    int64_t x = 0;
    int64_t y = 0;
    NewPoint(map_hash, x, y);

    std::string movement;
    std::cin >> movement;
    for (size_t i = 0; i < movement.length(); ++i)
    {
        for (int64_t step = 0; step < kStepSize; ++step)
        {
            if (kStep[step].ch == movement[i])
            {
                x += kStep[step].x_offset;
                y += kStep[step].y_offset;
                if (IsPointExsit(map_hash, x, y))
                {
                    std::cout << "BUG";
                    return 0;
                }

                NewPoint(map_hash, x, y);
                const int64_t skip_step = (0 == step % 2) ? (step + 1) : (step - 1);
                for (int64_t judge_step = 0; judge_step < kStepSize; ++judge_step)
                {
                    if (skip_step == judge_step)
                    {
                        continue;
                    }

                    if (IsPointExsit(map_hash, x + kStep[judge_step].x_offset, y + kStep[judge_step].y_offset))
                    {
                        std::cout << "BUG";
                        return 0;
                    }
                }
            }
        }
    }

    std::cout << "OK";
    return 0;
}

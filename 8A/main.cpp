#include <iostream>
#include <string>
#include <algorithm>

bool JudgeWay(const std::string &flag, const std::string &first, const std::string &second)
{
    size_t first_idx = flag.find(first);
    size_t second_idx = flag.rfind(second);
    if ((std::string::npos == first_idx) || (std::string::npos == second_idx))
    {
        return false;
    }
    return (second_idx >= first_idx + first.size());
}

int main(int argc, char **argv)
{
    std::string flag;
    std::string first;
    std::string second;
    std::cin >> flag >> first >> second;

    std::string flag_backward = flag;
    std::reverse(flag_backward.begin(), flag_backward.end());

    bool is_forward = JudgeWay(flag, first, second);
    bool is_backward = JudgeWay(flag_backward, first, second);
    if (is_forward)
    {
        if (is_backward)
        {
            std::cout << "both";
        }
        else
        {
            std::cout << "forward";
        }
    }
    else if (is_backward)
    {
        std::cout << "backward";
    }
    else
    {
        std::cout << "fantasy";
    }

    return 0;
}

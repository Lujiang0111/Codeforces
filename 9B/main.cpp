#include <stdint.h>
#include <math.h>
#include <vector>
#include <iostream>

int main()
{
    int n;
    double vb, vs;
    std::cin >> n >> vb >> vs;

    std::vector<int64_t> x(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i];
    }

    int64_t xu, yu;
    std::cin >> xu >> yu;

    int min_index = 0;
    double min_time = 0;
    double bus_time = 0;
    for (int i = 1; i < n; ++i)
    {
        bus_time += (x[i] - x[i - 1]) / vb;
        if ((min_index == 0) || (bus_time + sqrt((xu - x[i]) * (xu - x[i]) + yu * yu) / vs <= min_time))
        {
            min_time = bus_time + sqrt((xu - x[i]) * (xu - x[i]) + yu * yu) / vs;
            min_index = i;
        }
    }
    std::cout << min_index + 1;

    return 0;
}

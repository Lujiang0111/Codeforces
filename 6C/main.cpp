#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	int n = 0;
	std::cin >> n;
	
	std::vector<int> chocos(n, 0);
	for (int idx = 0; idx < n; ++idx)
	{
		std::cin >> chocos[idx];
	}

	int l = 0;
	int l_time = 0;
	int r = n - 1;
	int r_time = 0;
	while (true)
	{
		if (l_time <= r_time)
		{
			l_time += chocos[l];
			if (l == r)
			{
				++r;
				break;
			}
			++l;
		}
		else
		{
			r_time += chocos[r];
			if (l == r)
			{
				--l;
				break;
			}
			--r;
		}
	}

	std::cout << l + 1 << " " << n - r;
	return 0;
}

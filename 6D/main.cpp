#include <limits.h>

#include <iostream>
#include <vector>
#include <algorithm>

const int N = 15;
const int INF = INT_MAX;

int h[N], n, a, b, ans = INF;
std::vector<int> tmp, seq;

void dfs(int x, int sum)
{
	if (sum >= ans) return;
	if (x == n)
	{
		if (h[n] < 0)
		{
			ans = sum;
			seq = tmp;
		}
		return;
	}

	for (int i = 0; i <= (std::max)({ h[x - 1] / b, h[x] / a, h[x + 1] / b }) + 1; i++)
	{
		if (h[x - 1] - b * i < 0)
		{
			h[x - 1] -= b * i;
			h[x] -= a * i;
			h[x + 1] -= b * i;
			for (int j = 0; j < i; j++)
			{
				tmp.push_back(x);
			}
			dfs(x + 1, sum + i);
			h[x - 1] += b * i;
			h[x] += a * i;
			h[x + 1] += b * i;
			for (int j = 0; j < i; j++)
			{
				tmp.pop_back();
			}
		}
	}
}

int main()
{
	std::cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> h[i];
	}
	dfs(2, 0);
	std::cout << ans << std::endl;
	for (auto i : seq)
	{
		std::cout << i << " ";
	}
	return 0;
}

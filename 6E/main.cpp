#include <iostream>
#include <vector>
#include <deque>
#include <memory>

struct C6E
{
	int n;
	int k;
	std::vector<int> h;
	std::vector<int> ans_list;
};

bool Check(C6E *h, int len, bool is_collect)
{
	std::deque<int> high;
	std::deque<int> low;

	bool ret = false;
	h->ans_list.clear();
	for (int idx = 0; idx < h->n; ++idx)
	{
		// 单调递增队列
		while ((!high.empty()) && (h->h[idx] < high.back()))
		{
			high.pop_back();
		}
		high.push_back(h->h[idx]);
		if ((idx - len >= 0) && (h->h[idx - len] == high.front()))
		{
			high.pop_front();
		}

		// 单调递减队列
		while ((!low.empty()) && (h->h[idx] > low.back()))
		{
			low.pop_back();
		}
		low.push_back(h->h[idx]);
		if ((idx - len >= 0) && (h->h[idx - len] == low.front()))
		{
			low.pop_front();
		}

		if ((idx + 1 >= len) && (low.front() - high.front() <= h->k))
		{
			ret = true;
			if (!is_collect)
			{
				return ret;
			}

			h->ans_list.push_back(idx - len + 1);
		}
	}

	return ret;
}

int main(int argc, char **argv)
{
	std::shared_ptr<C6E> h = std::make_shared<C6E>();
	std::cin >> h->n >> h->k;
	h->h.resize(h->n);
	for (int idx = 0; idx < h->n; ++idx)
	{
		std::cin >> h->h[idx];
	}

	int l = 1;
	int r = h->n;
	while (l < r)
	{
		int cur = (l + r) / 2 + 1;
		if (Check(h.get(), cur, false))
		{
			l = cur;
		}
		else
		{
			r = cur - 1;
		}
	}

	Check(h.get(), l, true);
	std::cout << l << " " << h->ans_list.size() << std::endl;
	for (auto &&x : h->ans_list)
	{
		std::cout << x + 1 << " " << x + l << std::endl;
	}
	return 0;
}

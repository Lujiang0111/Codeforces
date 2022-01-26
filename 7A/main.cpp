#include <iostream>
#include <vector>
#include <string>

int main(int argc, char **argv)
{
	std::vector<bool> b_row(8, true);
	std::vector<bool> b_col(8, true);

	bool is_all_black = true;
	for (int r = 0; r < 8; ++r)
	{
		std::string s_row;
		std::cin >> s_row;
		for (int c = 0; c < 8; ++c)
		{
			if (s_row[c] == 'W')
			{
				is_all_black = false;
				b_row[r] = false;
				b_col[c] = false;
			}
		}
	}

	if (is_all_black)
	{
		std::cout << 8;
	}
	else
	{
		int ans = 0;
		for (int r = 0; r < 8; ++r)
		{
			if (b_row[r])
			{
				++ans;
			}
		}

		for (int c = 0; c < 8; ++c)
		{
			if (b_col[c])
			{
				++ans;
			}
		}
		std::cout << ans;
	}
	return 0;
}

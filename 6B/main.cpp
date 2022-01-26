#include <iostream>
#include <vector>
#include <string>

struct C6B
{
	int r;
	int c;
	char p_col;
	std::vector<std::vector<char>> room;
	std::vector<bool> is_color_deputy;
};

static bool IsNearPresident(const C6B &c6b, const int cur_r, const int cur_c)
{
	if ((cur_r > 0) && (c6b.room[cur_r - 1][cur_c] == c6b.p_col))
	{
		return true;
	}

	if ((cur_c > 0) && (c6b.room[cur_r][cur_c - 1] == c6b.p_col))
	{
		return true;
	}

	if ((cur_r + 1 < c6b.room.size()) && (c6b.room[cur_r + 1][cur_c] == c6b.p_col))
	{
		return true;
	}

	if ((cur_c + 1 < c6b.room[cur_r].size()) && (c6b.room[cur_r][cur_c + 1] == c6b.p_col))
	{
		return true;
	}

	return false;
}

int main(int argc, char **argv)
{
	C6B c6b;
	std::cin >> c6b.r >> c6b.c >> c6b.p_col;
	c6b.room.assign(c6b.r, std::vector<char>(c6b.c));
	c6b.is_color_deputy.assign(256, false);
	for (int cur_r = 0; cur_r < c6b.r; ++cur_r)
	{
		std::string line;
		std::cin >> line;
		for (int cur_c = 0; cur_c < c6b.c; ++cur_c)
		{
			c6b.room[cur_r][cur_c] = line[cur_c];
		}
	}

	int deputies = 0;
	for (int cur_r = 0; cur_r < c6b.r; ++cur_r)
	{
		for (int cur_c = 0; cur_c < c6b.c; ++cur_c)
		{
			if (('.' != c6b.room[cur_r][cur_c]) &&
				(c6b.p_col != c6b.room[cur_r][cur_c]) &&
				(!c6b.is_color_deputy[c6b.room[cur_r][cur_c]]) &&
				(IsNearPresident(c6b, cur_r, cur_c)))
			{
				c6b.is_color_deputy[c6b.room[cur_r][cur_c]] = true;
				++deputies;
			}
		}
	}
	std::cout << deputies;

	return 0;
}

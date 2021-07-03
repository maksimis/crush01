#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	is_follow_main_rules(int *v)
{
	if (v[0] == v[1] || v[0] == v[2] || v[0] == v[3]
		|| v[1] == v[2] || v[1] == v[3]
		|| v[2] == v[3])
	{
		return (0);
	}
	return (1);
}

int	is_follow_view_rules(int boarder, int *v, int len)
{
	int	i;
	int	last;

	i = 1;
	last = v[0];
	boarder = boarder - 1;
	while (i < len)
	{
		if (v[i] > last)
		{
			last = v[i];
			boarder--;
		}
		i++;
	}
	if (boarder == 0)
		return (1);
	return (0);
}

int	is_follow_all_rules(int left, int right, int *v, int len)
{
	int	*revers;
	int	i;

	if (is_follow_main_rules(v) == 0)
		return (0);
	if (is_follow_view_rules(left, v, len) == 0)
		return (0);
	revers = malloc(sizeof(int) * len);
	i = 0;
	while (i < len / 2 + 1)
	{
		revers[i] = v[len - i];
		i++;
	}
	if (is_follow_view_rules(right, revers, len) == 0)
		return (0);
	free(revers);
	return (1);
}

void	write_to_variant(int *var, int a, int b, int c, int d, int e, int f)
{
	var[0] = a;
	var[1] = b;
	var[2] = c;
	var[3] = d;
	var[4] = e;
	var[5] = f;
}

int	(*variants(void))[6]
{
	static int all_variants[13][6] = {
			{4, 1, 1, 2, 3, 4},
			{1, 2, 4, 1, 2, 3},
			{1, 2, 4, 2, 1, 3},
			{1, 3, 4, 2, 3, 1},
			{1, 3, 4, 2, 3, 1},
			{2, 2, 1, 4, 2, 3},
			{2, 2, 3, 4, 1, 2},
			{2, 2, 2, 4, 1, 3},
			{2, 3, 1, 4, 3, 2},
			{2, 3, 2, 4, 3, 1},
			{2, 3, 3, 4, 2, 1},
			{3, 2, 1, 2, 4, 1},
			{3, 1, 2, 3, 1, 4}};
	return (all_variants);
}


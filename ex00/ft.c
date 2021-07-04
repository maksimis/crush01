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

int	is_follow_view_rules_revers(int boarder, int *v, int len)
{
	int	i;
	int	last;

	i = len - 2;
	last = v[i + 1];
	boarder = boarder - 1;
	while (i >= 0)
	{
		if (v[i] > last)
		{
			last = v[i];
			boarder--;
		}
		i--;
	}
	if (boarder == 0)
		return (1);
	return (0);
}

int	is_follow_all_rules(int left, int right, int *v, int len)
{
	if (is_follow_main_rules(v) == 0)
		return (0);
	if (is_follow_view_rules(left, v, len) == 0)
		return (0);
	if (is_follow_view_rules_revers(right, v, len) == 0)
		return (0);
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

void	write_to_4array(int *arr, int a, int b, int c, int d)
{
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;
}

int check_result(int result[4][4], int borders[4][4])
{
	int	i;
	int buffer[4];

	i = 0;
	while (i < 4)
	{
		buffer[0] = result[0][i];
		buffer[1] = result[1][i];
		buffer[2] = result[2][i];
		buffer[3] = result[3][i];
		if (is_follow_all_rules(borders[0][i], borders[1][i], buffer, 4) == 0)
			return (0);
		i++;
	}
	return (1);
}


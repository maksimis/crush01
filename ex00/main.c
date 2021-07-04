#include <stdio.h>
#include <unistd.h>
#include "var.h"

int	g_vs[24][6] = {
		{4, 1, 1, 2, 3, 4},
		{1, 2, 4, 1, 2, 3},
		{1, 2, 4, 2, 1, 3},
		{1, 3, 4, 2, 3, 1},
		{2, 2, 1, 4, 2, 3},
		{2, 2, 3, 4, 1, 2},
		{2, 2, 2, 4, 1, 3},
		{2, 3, 1, 4, 3, 2},
		{2, 3, 2, 4, 3, 1},
		{2, 3, 3, 4, 2, 1},
		{3, 1, 2, 3, 1, 4},
		{3, 1, 2, 1, 3, 4},
		{1, 4, 4, 3, 2, 1},
		{2, 1, 3, 2, 1, 4},
		{2, 1, 3, 1, 2, 4},
		{3, 1, 1, 3, 2, 4},
		{2, 2, 3, 2, 4, 1},
		{2, 2, 2, 1, 4, 3},
		{2, 2, 3, 1, 4, 2},
		{3, 2, 2, 3, 4, 1},
		{3, 2, 1, 3, 4, 2},
		{3, 2, 1, 2, 4, 3},
		{1, 3, 4, 1, 3, 2},
		{1, 3, 4, 3, 1, 2},
};

int	g_count = 24;

int		check_result(int result[4][4], int borders[4][4]);

void	write_to_4array(int *arr, int a[4]);

void	print4na4(int result[4][4]);

int	find_sub_sub_result(int v[4], int result[4][4], int bs[4][4])
{
	int	checkresult;

	checkresult = 0;
	while (v[2] < 24 && !checkresult)
	{
		if (g_vs[v[2]][0] == bs[2][2] && g_vs[v[2]][1] == bs[3][2])
		{
			write_to_4array(result[2], g_vs[v[2]]);
			v[3] = 0;
			while (v[3] < 24 && !checkresult)
			{
				if (g_vs[v[3]][0] == bs[2][3] && g_vs[v[3]][1] == bs[3][3])
				{
					write_to_4array(result[3], g_vs[v[3]]);
					checkresult = check_result(result, bs);
				}
				v[3]++;
			}
		}
		v[2]++;
	}
	return (checkresult);
}

int	find_sub_result(int v[4], int result[4][4], int bs[4][4])
{
	int	checkresult;

	checkresult = 0;
	while (v[1] < 24 && !checkresult)
	{
		if (g_vs[v[1]][0] == bs[2][1] && g_vs[v[1]][1] == bs[3][1])
		{
			write_to_4array(result[1], g_vs[v[1]]);
			v[2] = 0;
			checkresult = find_sub_sub_result(v, result, bs);
		}
		v[1]++;
	}
	return (checkresult);
}

int	find_result(int result[4][4], int bs[4][4])
{
	int	v[4];
	int	checkresult;

	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
	checkresult = 0;
	while (checkresult == 0 && (v[0] < 24
			&& v[1] < 24 && v[2] < 24 && v[3] < 24))
	{
		while (v[0] < 24 && !checkresult)
		{
			if (g_vs[v[0]][0] == bs[2][0] && g_vs[v[0]][1] == bs[3][0])
			{
				write_to_4array(result[0], g_vs[v[0]]);
				v[1] = 0;
				checkresult = find_sub_result(v, result, bs);
			}
			v[0]++;
		}
	}
	return (checkresult);
}

void	find_borders(int borders[4][4], char *str)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			borders[l / 4][l % 4] = str[i] - 48;
			l++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	result[4][4];
	int	borders[4][4];
	int	checkresult;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	find_borders(borders, argv[1]);
	checkresult = find_result(result, borders);
	if (checkresult == 1)
		print4na4(result);
	else
		write(1, "Error\n", 6);
}

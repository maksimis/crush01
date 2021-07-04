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

int	main(int argc, char **argv)
{
	int	i;
	int	l;
	int	v1;
	int	v2;
	int	v3;
	int	v4;
	int	result[4][4];
	int	borders[4][4];
	int	checkresult;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	l = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] != ' ')
		{
			borders[l / 4][l % 4] = argv[1][i] - 48;
			l++;
		}
		i++;
	}
	v1 = 0;
	v2 = 0;
	v3 = 0;
	v4 = 0;
	checkresult = 0;
	while (checkresult == 0 && (v1 < 24 && v2 < 24 && v3 < 24 && v4 < 24))
	{
		while (v1 < 24 && !checkresult)
		{
			if (g_vs[v1][0] == borders[2][0] && g_vs[v1][1] == borders[3][0])
			{
				write_to_4array(result[0], g_vs[v1]);
				v2 = 0;
				while (v2 < 24 && !checkresult)
				{
					if (g_vs[v2][0] == borders[2][1] && g_vs[v2][1] == borders[3][1])
					{
						write_to_4array(result[1], g_vs[v2]);
						v3 = 0;
						while (v3 < 24 && !checkresult)
						{
							if (g_vs[v3][0] == borders[2][2] && g_vs[v3][1] == borders[3][2])
							{
								write_to_4array(result[2], g_vs[v3]);
								v4 = 0;
								while (v4 < 24 && !checkresult)
								{
									if (g_vs[v4][0] == borders[2][3] && g_vs[v4][1] == borders[3][3])
									{
										write_to_4array(result[3], g_vs[v4]);
										checkresult = check_result(result, borders);
									}
									v4++;
								}
							}
							v3++;
						}
					}
					v2++;
				}
			}
			v1++;
		}
	}
	if (checkresult == 1)
		print4na4(result);
	else
		write(1, "Error\n", 6);
}

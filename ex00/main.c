#include <stdio.h>
#include <unistd.h>

static int	g_variants[24][6] = {
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

int	check_result(int result[4][4], int borders[4][4]);

void	write_to_4array(int *arr, int a, int b, int c, int d);

void	write_int(int nb)
{
	nb = nb + 48;
	write(1, &nb, 1);
}

void print4na4(int result[4][4])
{
	int	i;
	int	l;

	i = 0;
	while (i < 4)
	{
		l = 0;
		while (l < 4)
		{
			write_int(result[i][l]);
			l++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i;
	int l;
	int v1;
	int v2;
	int v3;
	int v4;
	int result[4][4];
	int borders[4][4];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return 0;
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
	int checkresult = 0;
	while (checkresult == 0 && (v1 < 24 && v2 < 24 && v3 < 24 && v4 < 24))
	{
		while (v1 < 24 && !checkresult)
		{
			if (g_variants[v1][0] == borders[2][0] && g_variants[v1][1] == borders[3][0])
			{
				write_to_4array(result[0], g_variants[v1][2], g_variants[v1][3], g_variants[v1][4], g_variants[v1][5]);
				v2 = 0;
				while (v2 < 24 && !checkresult)
				{
					if (g_variants[v2][0] == borders[2][1] && g_variants[v2][1] == borders[3][1])
					{
						write_to_4array(result[1], g_variants[v2][2], g_variants[v2][3], g_variants[v2][4], g_variants[v2][5]);
						v3 = 0;
						while (v3 < 24 && !checkresult)
						{
							if (g_variants[v3][0] == borders[2][2] && g_variants[v3][1] == borders[3][2])
							{
								write_to_4array(result[2], g_variants[v3][2], g_variants[v3][3], g_variants[v3][4], g_variants[v3][5]);
								v4 = 0;
								while (v4 < 24 && !checkresult)
								{
									if (g_variants[v4][0] == borders[2][3] && g_variants[v4][1] == borders[3][3])
									{
										write_to_4array(result[3], g_variants[v4][2], g_variants[v4][3], g_variants[v4][4], g_variants[v4][5]);
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

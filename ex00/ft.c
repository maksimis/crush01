#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "var.h"

void	write_to_4array(int *arr, int a[6])
{
	arr[0] = a[2];
	arr[1] = a[3];
	arr[2] = a[4];
	arr[3] = a[5];
}

void	write_int(int nb)
{
	nb = nb + 48;
	write(1, &nb, 1);
}

void	print4na4(int result[4][4])
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

int	check_result(int result[4][4], int borders[4][4])
{
	int	i;
	int	l;
	int	check;

	i = 0;
	while (i < 4)
	{
		check = 0;
		l = 0;
		while (l < g_count && check == 0)
		{
			if (g_vs[l][0] == borders[0][i] && g_vs[l][1] == borders[1][i]
			&& g_vs[l][2] == result[0][i] && g_vs[l][3] == result[1][i]
			&& g_vs[l][4] == result[2][i] && g_vs[l][5] == result[3][i])
			{
				check = 1;
			}
			l++;
		}
		if (check == 0)
			return (0);
		i++;
	}
	return (1);
}

int	find_borders(int borders[4][4], char *str)
{
	int	i;
	int	l;
	int	error;

	i = 0;
	l = 0;
	error = 0;
	while (str[i] != '\0')
	{
		if ((i % 2 == 0) && str[i] < '5' && str[i] > '0')
		{
			borders[l / 4][l % 4] = str[i] - 48;
			l++;
		}
		else if ((i % 2 == 1) && str[i] == ' ')
		{
		}
		else
			error = 1;
		i++;
		if (i > 31)
			error = 1;
	}
	return (error);
}

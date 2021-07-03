#include <stdio.h>
#include <unistd.h>

void	write_int(int nb)
{
	nb = nb + 48;
	write(1, &nb, 1);
}

int	main(int argc, char **argv)
{
	int i;
	int l;
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
	i = 0;
	while (i < 4)
	{
		l = 0;
		while (l < 4)
		{
			result[i][l] = 0;
			l++;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		//Заполняем четверки
		if (borders[0][i] == 4)
		{
			result[i][0] = 1;
			result[i][1] = 2;
			result[i][2] = 3;
			result[i][3] = 4;
		}
		if (borders[1][i] == 4)
		{
			result[i][0] = 4;
			result[i][1] = 3;
			result[i][2] = 2;
			result[i][3] = 1;
		}
		if (borders[2][i] == 4)
		{
			result[0][i] = 1;
			result[1][i] = 2;
			result[2][i] = 3;
			result[3][i] = 4;
		}
		if (borders[3][i] == 4)
		{
			result[0][i] = 4;
			result[1][i] = 3;
			result[2][i] = 2;
			result[3][i] = 1;
		}
		//заполняем однерки
		if (borders[0][i] == 1)
		{
			result[i][0] = 4;
		}
		if (borders[1][i] == 1)
		{
			result[i][3] = 4;
		}
		if (borders[2][i] == 1)
		{
			result[0][i] = 4;
		}
		if (borders[3][i] == 1)
		{
			result[3][i] = 4;
		}
		i++;
	}
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
	i = 0;
	while (i < 4)
	{
		l = 0;
		while (l < 4)
		{
			write_int(borders[i][l]);
			l++;
		}
		write(1, "\n", 1);
		i++;
	}
}

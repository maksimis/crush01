#include <stdio.h>
#include <unistd.h>

int	(*variants(void))[6];

int check_result(int result[4][4], int borders[4][4]);

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
	int v1 = 0;
	int v2 = 0;
	int v3 = 0;
	int v4 = 0;
	int checkresult = 0;
	while (checkresult == 0)
	{
		while (v1 < 24 && !checkresult)
		{
			if (variants()[v1][0] == borders[2][0] && variants()[v1][1] == borders[3][0])
			{
				result[0][0] = variants()[v1][2];
				result[0][1] = variants()[v1][3];
				result[0][2] = variants()[v1][4];
				result[0][3] = variants()[v1][5];
				v2 = 0;
				while (v2 < 24 && !checkresult)
				{
					if (variants()[v2][0] == borders[2][1] && variants()[v2][1] == borders[3][1])
					{
						result[1][0] = variants()[v2][2];
						result[1][1] = variants()[v2][3];
						result[1][2] = variants()[v2][4];
						result[1][3] = variants()[v2][5];
						v3 = 0;
						while (v3 < 24 && !checkresult)
						{
							if (variants()[v3][0] == borders[2][2] && variants()[v3][1] == borders[3][2])
							{
								result[2][0] = variants()[v3][2];
								result[2][1] = variants()[v3][3];
								result[2][2] = variants()[v3][4];
								result[2][3] = variants()[v3][5];
								v4 = 0;
								while (v4 < 24 && !checkresult)
								{
									if (variants()[v4][0] == borders[2][3] && variants()[v4][1] == borders[3][3])
									{
										result[3][0] = variants()[v4][2];
										result[3][1] = variants()[v4][3];
										result[3][2] = variants()[v4][4];
										result[3][3] = variants()[v4][5];
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
	print4na4(result);
}

//
// Created by Carmelo Michaele on 7/3/21.
//
#include <stdio.h>
#include "ex00/ft.c"

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

int	main(void)
{
//	int var1[4] = {1, 2, 3, 4};
//	int var2[4] = {1, 3, 3, 4};
//	int var3[4] = {1, 2, 3, 2};
//	int var4[4] = {4, 2, 3, 1};
//	int var5[4] = {1, 2, 4, 3};

//	printf("%d\n", is_follow_main_rules(var1));
//	printf("%d\n", is_follow_main_rules(var2));
//	printf("%d\n", is_follow_main_rules(var3));
//	printf("%d\n", is_follow_main_rules(var4));
//	printf("%d\n", is_follow_main_rules(var5));
//	printf("%d\n", is_follow_view_rules(4, var1, 4));
//	printf("%d\n", is_follow_view_rules(1, var1, 4));
//	printf("%d\n", is_follow_view_rules(2, var1, 4));
//	printf("%d\n", is_follow_view_rules(3, var1, 4));
//
//	printf("%d\n", is_follow_view_rules(4, var4, 4));
//	printf("%d\n", is_follow_view_rules(1, var4, 4));
//	printf("%d\n", is_follow_view_rules(2, var4, 4));
//	printf("%d\n", is_follow_view_rules(3, var4, 4));
//
//	printf("%d\n", is_follow_view_rules(4, var5, 4));
//	printf("%d\n", is_follow_view_rules(1, var5, 4));
//	printf("%d\n", is_follow_view_rules(2, var5, 4));
//	printf("%d\n", is_follow_view_rules(3, var5, 4));

	const int VC = 22;
	//int var6[4] = {4, 2, 1, 3};
	//int **variants = get_all_g_vs;
	int current[4] = {0, 0, 0, 0};

	int i = 0;
	while (i < VC)
	{
		current[0] = g_vs[i][2];
		current[1] = g_vs[i][3];
		current[2] = g_vs[i][4];
		current[3] = g_vs[i][5];

//		printf("%d %d\n", i, is_follow_main_rules(current));
//		printf("%d %d\n", i, is_follow_view_rules(g_vs[i][0], current, 4));
		printf("%d %d\n", i, is_follow_all_rules(g_vs[i][0], g_vs[i][1], current, 4));
		i++;
	}

}
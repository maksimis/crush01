//
// Created by Carmelo Michaele on 7/3/21.
//
#include <stdio.h>
#include "ex00/ft.c"

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

	const int VC = 12;
	//int var6[4] = {4, 2, 1, 3};
	//int **variants = get_all_variants();
	int current[4] = {0, 0, 0, 0};

	int i = 0;
	while (i < VC)
	{
		current[0] = variants()[i][2];
		current[1] = variants()[i][3];
		current[2] = variants()[i][4];
		current[3] = variants()[i][5];

//		printf("%d %d\n", i, is_follow_main_rules(current));
//		printf("%d %d\n", i, is_follow_view_rules(variants()[i][0], current, 4));
		printf("%d %d\n", i, is_follow_all_rules(variants()[i][0], variants()[i][1], current, 4));
		i++;
	}

}
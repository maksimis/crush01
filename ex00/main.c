#include <stdio.h>
#include <unistd.h>
#include "var.h" //этот файл для того чтобы расшарить глобальную переменную по двум файлам

/*
Логика работы программы:
 У нас есть списко расположения башен из 24 вариантов с соответвующими значениями границ.
 Это переменная g_vs. В переменной 24 строки и 6 столбцов. 1 столбец левая граница, 2 столбец правая граница, 3-6 столбцы - значания наших башен
Вначале программы мы правильно читаем аргугмент с данными и заносим его в матрицу 4 на 4 - borders, первая строка - просмотр башен сверху
 вторая - снизу, третья - слева, четвертая - справа.

 Дальше мы задаем наш результат (result). Мы для каждой строки перебираем подходящие варианты из списка 24 вариантов g_vs. После того как мы правильно
 построили строки, мы проверяем а правильные ли столбцы фукнцией check_result, которая для каждого столбца ищет есть ли он в списке 24 вараинтов g_vs

 ВСЕ!
*/

//глобальная таблица вариантов
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

// дополнительные функции, они расположены в файле ft.c
int		check_result(int result[4][4], int borders[4][4]);

void	write_to_4array(int *arr, int a[4]);

void	print4na4(int result[4][4]);

int		find_borders(int borders[4][4], char *str);

int	find_sub_sub_result(int v[4], int result[4][4], int bs[4][4])
{
	int	checkresult;

	checkresult = 0;
	//перебор для 2 строки результата
	while (v[2] < 24 && !checkresult)// если checkresult == 1 не идем дальше, если индекс еще меньше 24 - продолжаем искать результат
	{
		if (g_vs[v[2]][0] == bs[2][2] && g_vs[v[2]][1] == bs[3][2])//смотрим значения из бордера для строк bs[2] и bs[3] для 2 строки и сравнимваем его с текущим вариантом из перебора
		{
			// если нашли подходящий вариант, записываем его в результат
			write_to_4array(result[2], g_vs[v[2]]);
			v[3] = 0;
			//перебор для 3 строки результата
			while (v[3] < 24 && !checkresult)
			{
				if (g_vs[v[3]][0] == bs[2][3] && g_vs[v[3]][1] == bs[3][3])//смотрим значения из бордера для строк bs[2] и bs[3] для 3 строки и сравнимваем его с текущим вариантом из перебора
				{
					// если нашли подходящий вариант, записываем его в результат
					write_to_4array(result[3], g_vs[v[3]]);
					//тут проверяем полную таблицы (мы заполнили все 4 строки), если будет 0, то вернемся в самое начало со второго результата для 1 строки и т.д.
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
	//перебор для 1 строки результата
	while (v[1] < 24 && !checkresult)// если checkresult == 1 не идем дальше, если индекс еще меньше 24 - продолжаем искать результат
	{
		if (g_vs[v[1]][0] == bs[2][1] && g_vs[v[1]][1] == bs[3][1])//смотрим значения из бордера для строк bs[2] и bs[3] для 1 строки и сравнимваем его с текущим вариантом из перебора
		{
			// если нашли подходящий вариант, записываем его в результат
			write_to_4array(result[1], g_vs[v[1]]);
			//обнуляем индекс для следующей строки (мы каждый раз должны перебирать все варианты для каждой строки
			v[2] = 0;
			//фукнция для разделения из-за лимита в 25 строк, передаем туда наши индексы, результат и бордеры
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

	// мы перебираем варианты для 4 строк, поэтому нам нужно 4 цикла, v[0] - v[3] - индексы для перебора по таблице с вариантами для каждой строки
 	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
	checkresult = 0;
	while (checkresult == 0 && (v[0] < 24
			&& v[1] < 24 && v[2] < 24 && v[3] < 24)) // если checkresult == 1 заканчиваем (нашли результат), или если индексы равны 24 - не нашли результат
	{
		//перебор для 0 строки результата
		while (v[0] < 24 && !checkresult) // если checkresult == 1 не идем дальше, если индекс еще меньше 24 - продолжаем искать результат
		{
			if (g_vs[v[0]][0] == bs[2][0] && g_vs[v[0]][1] == bs[3][0]) //смотрим значения из бордера для строк bs[2] и bs[3] для 0 строки и сравнимваем его с текущим вариантом из перебора
			{
				// если нашли подходящий вариант, записываем его в результат
				write_to_4array(result[0], g_vs[v[0]]);
				//обнуляем индекс для следующей строки (мы каждый раз должны перебирать все варианты для каждой строки
				v[1] = 0;
				//фукнция для разделения из-за лимита в 25 строк, передаем туда наши индексы, результат и бордеры
				checkresult = find_sub_result(v, result, bs);
			}
			v[0]++;
		}
	}
	return (checkresult);
}

int	main(int argc, char **argv)
{
	int	result[4][4]; //массив с результатом
	int	borders[4][4]; //массив с нашими границами
	int	checkresult; //переменная для проверки итогового результата если ввод данных был правильный
	int	error;

	error = 0;
	if (argc != 2)
	{
		// если в программу передано не 2 аргумента (название программы и строка с цифрами) - ошибка
		write(1, "Error\n", 6);// печатаем ошибку
		return (0);
	}
	error = find_borders(borders, argv[1]); // извлекаем граница из строки аргумента
	if (error == 1) // если извлечение произошло с ошибкой - печатаем ошибку
	{
		write(1, "Error\n", 6);// печатаем ошибку
		return (0);
	}
	checkresult = find_result(result, borders);
	if (checkresult == 1) // eсли результат вернул 1, значит мы нашли нужную таблицы и печатаем ее
		print4na4(result); // печатаем результат
	else
		write(1, "Error\n", 6);// печатаем ошибку
}

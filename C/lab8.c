#include <stdio.h>
#include <stdlib.h>
#include "lab8.h"

int main(void)
{
	const int max_lines = 5;
	const int max_columns = 10;

	int lines, columns;
	printf("Enter lines number: ");
	while ((lines = get_integer()) > max_lines || lines <= 0)
		printf("Error. Maximum number of lines is %d.\nTry again: ",
				max_lines);

	printf("Enter columns number: ");
	while ((columns = get_integer()) > max_columns || columns <= 0)
		printf("Error. Maximum number of columns is %d.\nTry again: ",
				max_columns);

	int** arr = array_insert(lines, columns);

	find_min_max(arr, lines, columns);

	printf("Result: \n");
	array_output(arr, lines, columns);

	array_free(arr, lines);
	system("pause");
	return 0;
}

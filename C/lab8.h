#ifndef ARRAY_H_
#define ARRAY_H_

int get_integer()
{
	int n, ch;
	while (scanf_s("%d", &n) != 1) {
		printf("\nError. Try again:");
		while ((ch = getchar()) != '\n' && ch != EOF)
			;
	}
	return n;
}

int* line_insert(int size)
{
	int* line;
	if ((line = malloc(size * sizeof(int))) == NULL)
		return NULL;
	for (int i = 0; i < size; ++i) {
		printf("[%d]: ", i);
		line[i] = get_integer();
	}
	return line;
}

int** array_insert(int lines, int columns)
{
	int** arr;
	if ((arr = malloc(lines * sizeof(int*))) == NULL)
		return NULL;
	for (int i = 0; i < lines; i++) {
		printf("Array #%d:\n", i);
		arr[i] = line_insert(columns);
	}
	return arr;
}

void line_output(int* line, int size)
{
	if (line != NULL)
		for (int i = 0; i < size; ++i)
			printf("%4d%s", line[i],
					(i == size - 1) ? ".\n" : ", ");
}

void array_output(int** source, int lines, int columns)
{
	if (source != NULL)
		for (int i = 0; i < lines; i++) {
			printf("[%d]: ", i);
			line_output(source[i], columns);
		}
}

void lines_swap(int** source, int first_line, int second_line)
{
	int* temp = source[first_line];
	source[first_line] = source[second_line];
	source[second_line] = temp;
}

void find_min_max(int** arr, int lines, int columns)
{
	int min_sum;
	int min_line;

	int max_sum;
	int max_line;

	int sum_this;
	for (int i = 0; i < lines; i++) {
		sum_this = 0;
		for (int j = 0; j < columns; j++)
			sum_this += arr[i][j];
		
		printf("The sum of the line %d is equal to %d.\n", i, sum_this);

		if (i == 0) {
			min_sum = max_sum = sum_this;
			min_line = max_line = i;
		} else if (sum_this > max_sum) {
			max_sum = sum_this;
			max_line = i;
		} else if (sum_this < min_sum) {
			min_sum = sum_this;
			min_line = i;
		}
	}
	printf("Max line index = %d, min = %d.\n", max_line, min_line);
	lines_swap(arr, min_line, max_line);
}

void array_free(int** arr, int lines)
{
	if (arr != NULL) {
		for (int i = 0; i < lines; i++)
			if (arr[i] != NULL)
				free(arr[i]);
		free(arr);
	}
}
#endif

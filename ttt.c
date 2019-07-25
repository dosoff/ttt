#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main_solver(int sq_len, char symb[], int cur_max[])
{
	int *str1;
	int *str2; 
	int *str3[3];
	int *str;

	str1 = malloc(sq_len * sizeof(int));
	str2 = str1;
	str = malloc((1 + sq_len) * sizeof(int));
	*str3[0] = str1;
	*str3[1] = str2;
	*str3[2] = {sq_len};

	fd = open(fd, 'r');
	while (sq_len--)
	{
		ret = read(fd, str, *str3[2]);
		if (str[sq_len] != '\n')
		{
			close(fd);
			return 0;
		}
		if (!solver_str(&str[0], str3, &symb[0], &cur_max[0], *str3[2] - sq_len - 1))
		{
			close(fd);
			return 0;
		}
	}
	return 1;
}

int main()
{
	char fd[];
	int cur_max[] = {-1, -1, -1};
	char symb[3];
	int* sq_len;

	if (!len_of_first_str(&fd[0], &symb[0], sq_len))
	{
		printf("%s\n", "error");
		return 0;
	}
	if (!main_solver(*sq_len, &symb[0], &cur_max[0]))
	{
		printf("%s\n", "error");
		return 0;
	}
	///вывод...
}
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int min(int n1, int n2)
{
	if (n1 < n2)
		return n1;
	return n2;
}

int solver_str(char str[], int *str1[], char symb[], int cur_max[], int row_index)
{
	int i;
	int len;


	len = *str1[2];
	str1[0] = str1[1];
	i = 0;
	while (i < len)
	{
		printf("%i\n", i);
		if (str[i] == symb[1])
		{
			str1[1][i] = 0;
		}
		else if (str[i] == symb[0])
		{
			if (i == 0)
				str1[1][i] = str1[0][i] + 1;
			else
				str1[1][i] = min(min(str1[0][i - 1], str1[0][i]), str1[1][i - 1]) + 1;
			printf("%s %i\n", "hello", str1[1][i]);
			if (cur_max[0] < str1[1][i])
			{
				cur_max[0] = str1[1][i];
				cur_max[1] = i;
				cur_max[2] = row_index;
			}
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int main()
{
	char str[] = {'*', '.', '.', '*', '.'};
	int str1[] = {0, 0 ,0, 0, 0,};
	int str2[] = {2, 1, 3, 3, 3};
	int str3[] = {5};
	int *str4[] = {&str1[0], &str2[0], &str3[0]};
	int cur_max[3] = {0, 0, 0};
	char symb[3] = {'.', '*', 'a'};
	printf("%i\n\n", solver_str(&str[0], str4, &symb[0], &cur_max[0], 1));
	printf("%s\n", "wow");
	printf("%d %d", cur_max[0], cur_max[1]);
}
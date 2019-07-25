#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int len(int value, int base)
{
	int length = 0;
	if (value < 0)
		value *= -1;
	while (value / base)
	{
		value /= base;
		length++;
	}
	if (value != 0)
		length++;
	return length;
} 

char	*ft_itoa_base(int value, int base)
{
	char symbols[] = "0123456789ABCDEF";
	char *answer;
	int length;
	int ind = 0;
	int stop = 0;

	if (!value)
		return "0";
	length = len(value, base);
	if (value < 0)
	{
		length++;
		stop = 1;
	}
	answer = (char *) malloc(sizeof(char) * (length + 1));
	answer[length] = '\0';
	if (value < 0)
	{
		answer[0] = '-';
		value *= -1;
	}
	while (length > stop)
	{
		answer[--length] = symbols[value % base];
		value /= base;
	}

	return answer;
}

int main()
{
	printf("%s\n", ft_itoa_base(-13, 2));
}
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int len_of_first_str(char file[], char symb[], int* sq_len)
{
	int ret;
	char buf[1];
	int len;
	int flag = 0;
	int fd;

	len = 0;
	fd = open(file, 'r');
	printf("%s\n", "hello");
	while (ret = read(fd, buf, 1))
	{
		printf("%c", buf[0]);
		if (buf[0] == '\n')
		{
			flag = 1;
			break;
		}
		len++;
	}
	close(fd);

	printf("%d\n", len);
	if (flag == 0 || len < 4)
		return 0;

	fd = open(file, 'r');
	while (ret = read(fd, buf, 1) && len-- > 3)
	{
		if (buf[0] >= 0 && buf[1] <= '9')
		{
			*sq_len += *sq_len * 10 + (buf[0] - '0');
		}
		else
			return 0;
	}

	symb[0] = read(fd, buf, 1);
	symb[1] = read(fd, buf, 1);
	symb[2] = read(fd, buf, 1);

	close(fd);
	return 1;
}

int main()
{
	char file[] = "1.txt";
	char symb[3];
	int sq_len = 0;

	len_of_first_str(&file[0], &symb[0], &sq_len);
	printf("%d\n", sq_len);
}
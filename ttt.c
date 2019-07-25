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
    printf("%s\n", "helloooo");
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
    if (flag == 0 || len < 4)
        return 0;
    printf("%s %d\n", "sqlen", *sq_len);
    fd = open(file, 'r');
    //printf("%s %d\n", "sqlen", *sq_len);
    while ((ret = read(fd, buf, 1)) && len-- > 3)
    {
        printf("%c\n", buf[0]);
        if ((buf[0] >= '0') && (buf[0] <= '9'))
        {
            printf("%s\n", "wtf!", len);
            (*sq_len) = ((*sq_len) * 10) + (buf[0] - '0');
            printf("%s\n", "wtf1", len);

        }
        else
        {
            close(fd);
            return 0;
        }
    }
    printf("%s %d\n", "sqlen", *sq_len);
    
    symb[0] = buf[0];
    read(fd, buf, 1);
    symb[1] = buf[0];
    read(fd, buf, 1);
    symb[2] = buf[0];
    
    close(fd);
    return 1;
}

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
            //printf("%s %i\n", "hellooo!!!", str1[1][i]);
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

int main_solver(int *sq_len, char symb[], int cur_max[], char file[])
{
	int *str1;
	int *str2; 
	int *str3[3];
	char *str;
    int fd;
    int ret;

    printf("%s %d\n", "wtf1", *sq_len);
    str1 = malloc((*sq_len) * sizeof(int));
	str2 = str1;
	str = malloc((1 + (*sq_len)) * sizeof(char));
	str3[0] = str1;
	str3[1] = str2;
	str3[2][0] = *sq_len;
    char buf[1];

    fd = open(file, 'r');
    printf("%s\n", "helloooo");
    while ((ret = read(fd, buf, 1)))
    {
        printf("%c\n", buf[0]);
        if (buf[0] == '\n')
        {
            //read(fd, buf, 1);
            //read(fd, buf, 1);
            break;
        }

    }
    printf("%s %c", "cahrs", buf[0]);
	while (sq_len--)
	{
		ret = read(fd, str, (*str3[2]) + 1);
        printf("%c %c %c\n", "cahrs", str[0], str[1], str[2]);
		if (str[*sq_len] != '\n')
		{
			close(fd);
			return 0;
		}
		if (!solver_str(str, str3, &symb[0], &cur_max[0], *str3[2] - (*sq_len) - 1))
		{
			close(fd);
			return 0;
		}
	}
    close(fd);
	return 1;
}

int main()
{
	char fd[2] = "1";
    char fd1[2] = "2";
	int cur_max[] = {-1, -1, -1};
	char symb[3];
	int sq_len;

    sq_len = 0;
	if (!len_of_first_str(&fd[0], &symb[0], &sq_len))
	{
		printf("%s\n", "error1");
		return 0;
	}
	if (!main_solver(&sq_len, &symb[0], &cur_max[0], &fd1[0]))
	{
		printf("%s\n", "error2");
		return 0;
	}
}

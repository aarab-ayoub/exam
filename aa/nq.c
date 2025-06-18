#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *ft_strdup(char *s)
{
	int i = 0;
	int len = 0;
	while (s[len])
		len++;
	
	char *res = malloc(len + 1);
	if(!res)
		return NULL;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return res;
}

char *gnl(int fd)
{
	static char buf[BUFFER_SIZE];
	char line[10000];
	static int a;
	static int b = 0;
	int i = 0;
	while (1)
	{
		if (a >= b)
		{
			a = 0;
			b = read(fd , buf , BUFFER_SIZE);
			if(b <= 0)
			{
				a=0;
				b=0;
				break;
			}
		}
		line[i] = buf[a];
		i++;
		a++;
		if (line[i - 1] == '\n' ||i >= 10000)
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return NULL;
	return(ft_strdup(line));
}
int check(char *s  , char *ar , int l)
{
	int i = 0;
	if (!s || !ar)
		return -1;
	while (i < l && s[i] == ar[i])
		i++;
	if(i < l)
		return -1;
	return 1;
}

void printing(char *s , char *ar)
{
	int i = 0;
	int j;
	int len = 0;

	while (ar[len])
		len++;

	while (s[i])
	{
		if (check(s + i , ar , len) == 1)
		{
			j = 0;
			while (j < len)
			{
				s[i + j] = '*';
				j++;
			}
		}
		write(1,&s[i],1);
		i++;
	}
	return ;
}
int main (int argc ,char **argv)
{
	char *l ;
	while (1)
	{
		l = gnl(0);
		if (!l)
			break;
		printing(l , argv[1]);
		// printf("%s\n" , l);/
		free(l);	
	}
	
}
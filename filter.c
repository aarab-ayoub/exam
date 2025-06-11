#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *ft_strdup(char *s)
{
	int i = 0;
	int l = 0;
	while(s[l])
		l++;
	char *t = malloc(l + 1);
	if(!t)
		return NULL;
	while(s[i])
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return t;
}

char *gnl(int fd)
{
	static char buf[BUFFER_SIZE];
	char line[10000];
	static int a;
	static int b = 0;
	int i = 0;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	while(1)
	{
		if(a >= b)
		{
			a = 0;
			b = read(fd , buf, BUFFER_SIZE);
			if(b <= 0)
			{
				a = 0;
				b = 0;
				break;
			}
		}
		line[i] = buf[a];
		i++;
		a++;
		if(line[i - 1] =='\n'|| i >= 10000)
			break;
	}
	line[i] = '\0';
	if(i == 0)
		return NULL;
	return(ft_strdup(line));
}

int check(char *s , char  *ar , int l)
{
	int i = 0;

	if(!s || !ar)
		return -1;
	while( i < l && s[i] == ar[i])
		i++;
	if(i < l)
		return -1;
	return 1;
}

void  printing(char *s , char *ar)
{
	int i = 0;
	int j;
	int l = 0;

	while(ar[l])
		l++;

	while(s[i])
	{
		if(check(s + i, ar , l) == 1)
		{
			j = 0;
			while( j < l)
			{
				s[i + j] = '*';
				j++;
			}
		}
		write(1,&s[i], 1);
		i++;
	}
}

int main(int ac , char **argv)
{
	char *t;
	if(ac != 2)
		return 1;
	while (1)
	{
		t = gnl(0);
		if(!t)
			break;
		printing(t , argv[1]);
		free(t);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


// int is_safe(int *tab , int col , int row)
// {
// 	for(int i = 0; i < col ; i++)
// 	{
// 		if (tab[i] == row ||abs(tab[i] - row) == abs(col -i))
// 			return 0;
// 	}
// 	return 1;
// }

// void solve(int *tab , int n , int col)
// {
// 	if (col == n)
// 	{
// 		for(int i = 0; i < n; i++)
// 		{
// 			printf("%d", tab[i]);
// 			if (i < n- 1)
// 				printf(" ");
// 		}
// 		printf("\n");
// 		return ;
// 	}
// 	for(int i = 0; i < n; i++)
// 	{
// 		if (is_safe(tab , col ,i))
// 		{
// 			tab[col] = i;
// 			solve(tab , n , col + 1);
// 		}
// 	}
// }

// int main(int argc , char **argv)
// {
// 	if (argc != 2)
// 	{
// 		return 0;
// 	}
// 	int n = atoi(argv[1]);
// 	int *tab = calloc(sizeof(int) , n);
// 	solve(tab , n , 0);
// 	free(tab);
// }


char *sort(char *s)
{
	int i = 0;
	int len = 0;
	while (s[len])
		len++;
	char temp;
	char *res = malloc(len + 1);
	if(!res)
		return NULL;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[len] = '\0';
	for (int i = 0; i < len -1; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			if (res[j] > res[j + 1])
			{
				temp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = temp;
			}
			
		}
	}
	return res;	
}

void permutation(char *str , char *result , char *used ,int index, int res_i , int len)
{
	if (res_i == len)
	{
		result[res_i] = '\0';
		printf("%s\n" , result);
		return ;
	}
	for (int i = 0; i < len; i++)
	{
		if (used[i])
		{
			continue;
		}
		used[i] = 1;
		result[res_i] = str[i];
		permutation(str , result ,used , index + 1 , res_i + 1 , len);
		used[i] = 0;
	}
	
}

void powerset(int *tab , int *result , int target , int index , int res_i , int len ,int total , int *flag)
{
	if (len == index)
	{
		if (target == total)
		{
			for (int i = 0; i < res_i; i++)
			{
				printf("%d" , result[i]);
				if (i < res_i - 1)
					printf(" ");				
			}
			printf("\n");
			*flag = 1;
		}
		return ;
	}
	powerset(tab , result , target , index + 1 , res_i , len ,total , flag);
	result[res_i] = tab[index];
	powerset(tab , result , target , index + 1 , res_i + 1 , len ,total + tab[index], flag);
}

int main(int argc , char **argv)
{
	// int i = 0;

	// while (argv[1][i])
	// {
	// 	i++;
	// }
	
	// char *str = sort(argv[1]);
	// char *reuslt = malloc( i + 1);
	// char *used =calloc(i , 1);

	// permutation(str, reuslt , used ,0 , 0 , i);
	// free(str);
	// free(reuslt);
	// free(used);
	int target = atoi(argv[1]);
	int len = argc -2;
	int flag = 0;
	int *tab =malloc(sizeof(int) * len);
	int *result = malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++)
	{
		tab[i] = atoi(argv[i + 2]);
	}
	
	powerset(tab , result , target , 0 ,0 ,len , 0,&flag);
	free(result);
	free(tab);
}
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void powerset(int *tab, int *result , int target ,int len , int index, int res_i , int total , int *flag)
{
	if(len == index)
	{
		if(total == target)
		{
			for(int i=0; i <res_i;i++)
			{
				printf("%d", result[i]);
				if(i < res_i - 1)
					printf(" ");
			}
			printf("\n");
			*flag = 1;
		}
		return ;
	}
	powerset(tab , result,  target , len , index +1 ,res_i , total ,flag);
	result[res_i] = tab[index];
	powerset(tab , result ,target , len , index +1 ,res_i + 1 ,total + tab[index] , flag);
}

int main(int argc , char **argv)
{
	int *tab;
	int *result;
	int len = argc -2;
	int flag = 0;
	int target = atoi(argv[1]);

	tab = malloc(sizeof(int) *len );
	result = malloc(sizeof(int) *len);

	for(int i = 0; i< len ;i++)
		tab[i] = atoi(argv[i + 2]);
	powerset(tab, result, target, len , 0 ,0 , 0 , &flag);
	if(!flag)
		printf("\n");
	return 0;
}


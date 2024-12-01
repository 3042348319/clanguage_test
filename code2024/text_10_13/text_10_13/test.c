#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>

int main()
{
	int tang[5] = { 0 };
	int i=0;
	while (i < 5)
	{
		scanf("%d", &tang[i]);
		i++;
	}
	i = 0;
	for (i; i < 5; i++)
	{
		if (0 == i)
		{
			tang[4] += tang[0] / 3;
			tang[1] += tang[0] / 3;
			tang[0] = tang[0] / 3;
		}
		else if (4 == i)
		{
			tang[0] += tang[4] / 3;
			tang[3] += tang[4] / 3;
			tang[4] = tang[4] / 3;
		}
		else
		{
			tang[i + 1] += tang[i] / 3;
			tang[i - 1] += tang[i] / 3;
			tang[i] = tang[i] / 3;
		}
		
	}
	printf("%5d%5d%5d%5d%5d", tang[0], tang[1],tang[2], tang[3], tang[4]);
	return 0;
}
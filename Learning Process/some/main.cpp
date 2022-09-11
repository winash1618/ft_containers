#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int s = 20;
	int i[s] = {0};
	int count = 0;
	int count1 = 0;
	int k = 0;
	int range = 1000000;
	srand(time(NULL));
	while (k < range)
	{
		
		int j = 0;
		while (j < 2)
		{
			i[j] = rand() % s;
			if (i[1] == i[0])
			{
				j = 0;
			}
			j++;
		}
		if (i[0] == 0 && i[1] == 1)
			count++;
		k++;
	}
	k = 0;
		srand(time(NULL));
	while (k < range)
	{
		
		int j = 0;
		while (j < 2)
		{
			i[j] = rand() % s;
			if (i[1] == i[0])
			{
				j = 0;
			}
			j++;
		}
		if (i[0] == 0)
		{
			if ((rand() % (s-1)) + 1 == 1)
				count1++;
		}
		k++;
	}
	// printf("count = %d\n", count);
	// printf("count1 = %d\n", count1);
	// printf("Percentage probability taking two winning cards without shuffling the second time = %f%% \nPercentage probability taking two winning cards with shuffling the second time =%f%% \n", (count/(range*1.0))* 100.0, (count1/(range * 1.0))*100.0);
	if (count < count1)
		printf("1\n");
	return (0);
}
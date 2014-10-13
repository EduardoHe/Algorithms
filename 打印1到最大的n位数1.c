#include<stdio.h>
#include<stdlib.h>

void PrintOneToMaxNDigits(int n)
{
	if(n <= 0) {
	    printf("Invalid Input!");
	}
	
	char* number = (char*)malloc(sizeof(char) * (n + 1));
	number[n] = '\0';
	memset(number, '0', n);
	
	while(!InCrement(number, n))
	{
	    PrintNumber(number, n);
	}
	
	free(number);
}

int InCrement(char* number, int n)
{
	int Count = n - 1;
	number[Count]++;
	while(number[Count] > '9')
    {
		if(Count == 0)
		{
		 return 1;
		} else {
		    number[Count] = '0';
		    Count--;
		    number[Count]++;
		}
	}
	return 0;
}

void PrintNumber(char* number, int n)
{
    int Count = 0, JudgePrint = 0;
	for(Count = 0; Count < n; Count++)
	{
	    if(number[Count] == '0' && JudgePrint ==0) {
		    continue;
		} else {
		    printf("%c", number[Count]);
			JudgePrint = 1;
		}
	}
}
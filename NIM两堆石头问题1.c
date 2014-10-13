#include<stdio.h>
#include<math.h>

int nim(int x, int y)
{
	int temp;
	double a,b;
	a = (1 + sqrt(5)) / 2;
	b = (3 + sqrt(5)) / 2;
	if(x == y) {
		return 1;
	}
	if(x > y) {
		temp = x;
		x = y;
		y = temp;
	}
	return (y != (int)((int)(x/a+1)*b));
}
int main(void)
{
	int x,y,result;
	scanf("%d%d", &x, &y);
	result = nim(x, y);
	printf("%d", result);
	return 0;
}


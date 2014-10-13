#include<stdio.h>
#define MAX 1000
#define LimitedValue 1111111111

int SearchTempArray[MAX] = {0}, Mark[10] = {0};

int search(int N)
{
	int first = 1,last = 0,MmN = 1,k,LChild,RChild;
	while(!Mark[0]) {
		LChild = MmN * 10;
		RChild = LChild + 1;
		if(!Mark[LChild % N]) {
			SearchTempArray[first % MAX] = LChild;
			Mark[LChild % N] = LChild;
			first++;
		}
		if(!Mark[RChild % N]) {
			SearchTempArray[first % MAX] = RChild;
			Mark[RChild % N] = RChild;
			first++;
		}
		last++;
		if(last == first) {
			break;
		}
		MmN = SearchTempArray[last % MAX];
		/*if(MmN > LimitedValue) {
			Mark[0] = -1;
			break;
		}*/
		for(k = 1; k < 10; k++) {
			Mark[k] = 0;
		}
	}
	return Mark[0];
}



int main(void)
{
	int N,MmultipleN = 0,M;
	if(!scanf("%d", &N)) {
		printf("Scan Error!");
		return 0;
	}
	if(N > MAX || N <= 0) {
		printf("Data Error!");
	} else if(N == 1) {
		printf("1  1");
	} else {
		MmultipleN = search(N);
	}
	if(MmultipleN < 0) {
		printf("Simulation Error!");
	} else{
		M = MmultipleN / N;
		printf("%d  %d", M,MmultipleN);
	}
	return 0;
}


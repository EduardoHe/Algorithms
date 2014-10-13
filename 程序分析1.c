#include<stdio.h>

int main(void)
{
	int i,j,rg[30] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,
	18,19,20,21,22,23,24,25,26,27,28,29,30,31};
	int hit,hit1,hit2;
	for(i = 1; i < 1000000; i++) {
		hit = 0; hit1 = -1; hit2 = -1;
		for(j = 0; (j < 30)&&(hit <= 2); j++) {
			if(i % rg[j] !=0) {
				hit++;
				if(hit == 1) {
					hit1 = j;
				} else if(hit == 2) {
					hit2 = j;
				} else {
					break;
				}
			}
		}
		if((hit == 2)&&(hit1 + 1 == hit2)) {
			printf("%d\n",i);
		}
	}
	return 0;
}
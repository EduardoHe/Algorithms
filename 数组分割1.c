#include<stdio.h>

int min(int a, int b) {
	if(a > b) {
	return b;
	} else {
	return a;
	}
}

int main(void)
{
	int Count_i,Count_j,Value,Number,Sum = 0,Arr[20],IsExist[20][10000];
	//---------初始化----------
	if(!scanf("%d", &Number)) {
		printf("Data Error!");
		return 0;
	}
	for(Count_i = 1; Count_i <= Number * 2; Count_i ++) {
		if(!scanf("%d", Arr+Count_i)){
			printf("Array Number Error!");
			return 0;
		} else if(Arr[Count_i] < 0) {
			printf("Array Number is negative!");
			return 0;
		}
		Sum += Arr[Count_i];
	}
	IsExist[0][0] = 1;
	for(Count_i = 1; Count_i <= Number; Count_i++) {
		for(Value = 1; Value <= Sum / 2; Value++) {
			IsExist[Count_i][Value] = 0;
		}
	}
	//---------利用动态规划求最优解--------
	for(Count_i = 1; Count_i <= 2 * Number; Count_i++) {
		for(Count_j = min(Count_i, Number); Count_j > 0; Count_j--) {
			for(Value = 1; Value <= Sum / 2; Value++) {
				if((Value >= Arr[Count_i])&&(IsExist[Count_j - 1][Value - Arr[Count_i]])) {
					IsExist[Count_j][Value] = 1;
				}
			}
		}
	}
	
	for(Value = Sum / 2; Value >= 0; Value--) {
		if(IsExist[Number][Value]) {
			printf("%d\n", Value);
			break;
		}
	}
	return 0;
}
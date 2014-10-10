#include<stdio.h>

void swap(int *a, int *b)
{
    int TempNumber;
	TempNumber = *a;
	*a = *b;
	*b = TempNumber;
}
void QuickSort(int arr[], int start, int end, int k)
{
    int LowCount = 0, HighCount = 0, pivot = 0;
	if(arr == NULL || (arr + end) == NULL || start < 0 || start > end || end + 1 < k || k <= 0) {
	    printf("Invalid Input!");
	    return ;
	}
	if(start == end) {
	    if(start + 1 == k) {    //后面记得加1，但是前面给忘了
		    printf("%d", arr[start]);
		}
		return ;
	}
	
	pivot = arr[start]; LowCount = start; HighCount = end + 1;
	while(1) {
	    do {
		    LowCount++;
		}while(arr[LowCount] < pivot);
		do {
		    HighCount--;
		}while(arr[HighCount] > pivot);
		if(LowCount >= HighCount) {
		    break;
		}
		swap(arr + LowCount, arr + HighCount);
	}
	swap(arr + start, arr + HighCount);
	if(HighCount + 1 == k) {
	    printf("%d", arr[HighCount]);
		return ;
	} else if(HighCount + 1 < k) {
	    QuickSort(arr, HighCount + 1, end, k);
	} else {
	    QuickSort(arr, start, HighCount - 1, k);
	}
}

int main(void)
{
	int arr[8]={8,3,7,12,10,5,4,16};
	QuickSort(arr, 0, 7, 7);
    return 0;
}
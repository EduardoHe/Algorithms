#include<stdio.h>

#define MAX_ROW 11
#define MAX_STATUS 2048

_int64 dp[MAX_ROW][MAX_STATUS];
int n, m;

bool FirstLineTest(int state)
{
	int i = 0;
	while(i < m) {
		if(state & (0x1 << i)) {
			if(i == m - 1 || state & (0x1 << (i+1)) == 0) {
				return false;
			}
			i += 2;
		}
		i++;
	}
	return true;
}

bool CompatablityTest(int State1, int State2)
{
	int i = 0;
	while(i < m) {
		if(State1 & (0x1 << i) == 0) {
			if(State2 & (0x1 << i) == 0) {
				return false;
			}
			i++;
		}
		else
		{
			if(State2&(0x << i) == 0) {
				i++;
			} else if(i == m - 1 || !(State1 & (0x1 << (i + 1))) || !(State2 & (0x1 << (i + 1)))) {
				return false;
			} else {
				i += 2;
			}
		}
	}
	return true;
}
int main(void)
{
	while(scanf("%d%d", &n, &m)!=EOF) {
		if(m <= 0 || n <= 0) {
			printf("data input error!");
			break;
		}
		if(n < m) {
			n = n^m;
			m = n^m;
			n = n^m;
		}
		
		_int64 AllState = 1<<m;
		memset(dp, 0, sizeof(dp));
		
		for(int i = 0; i < AllState; i++) {
			if(FirstLineTest(i)) {
				dp[0][i] += 1;
			}
		}
		
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < AllState; j++) {
				for(int k = 0; k < AllState; k++) {
					if(dp[i - 1][k]) {
						if(CompatablityTest(j, k)) {
							dp[i][j] += dp[i - 1][k];
						}
					}
				}
			}
		}
		
		printf("%I64d",dp[n - 1][AllState]);
	return 0;
}
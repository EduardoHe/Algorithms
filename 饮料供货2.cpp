#include<iostream>
using namespace std;

int opt[101][11],h[10],c[10];

int Cal(int v, int type)
{
	if(type > t) {
		if(v == 0) {
			return 0;
		} else {
			return -1;
		}
	}
	if(v < 0) {
		return -1;
	} else if(v == 0) {	//找到最大的可能的值，并且由于题目中的特殊条件，最大的情况时v==0
		return 0;
	} else if(opt[v][type] != -1) {
		return opt[v][type];
	}
	
	int ret = -1;
	for(int i = 0; i <= v1/c[type]; i++)
	{
		int temp = Cal(v - i * c[type], type + 1);
		if(temp != -1) {
			temp = h[type] * i;
			if(temp > ret) {
				ret = temp;
			}
		}
	}
	return opt[v][type] = ret;
}

int main()
{
	int v1,t,result;
	cin >> v1 >> type;
	result = Cal(v1, 1);
	cout << result << endl;
	return 0;
}
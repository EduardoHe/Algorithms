#include "windows.h"
#include "stdlib.h"
#include "math.h"
using namespace std;

const int SAMPLING_COUNT=200;
const double PI=3.1415926535;
const int TOTAL_AMPLITUDE=300;

int main(void)
{
	DWORD busypan[SAMPLING_COUNT];
	int amplitude=TOTAL_AMPLITUDE/2;
	double radian=0.0;
	double radianIncrement=2.0/(double)SAMPLING_COUNT;
	for(int i=0; i<SAMPLING_COUNT; i++)
	{
		busypan[i]=(DWORD)amplitude+sin(PI*radian)*amplitude;
		radian+=radianIncrement;
	}
	DWORD starttime=0;
	for(int j=0; ;j%=SAMPLING_COUNT)
	{
		starttime=GetTickCount();
		while(GetTickCount()-starttime<=busypan[j])
			;
		Sleep(TOTAL_AMPLITUDE-busypan[j]);
	}
	return 0;
}
//http://blog.csdn.net/zhoubin1992/article/details/46984979

#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 10000000 + 10;
bool prime[N];
int hs[664579 + 10];
void getPrimeTable()
{
	for (int i = 3; i <= 3333; i += 2)
	{
		if (prime[i] == 0)
		for (int j = i*i; j < N; j += 2 * i)
			prime[j] = 1;
	}
	int total = 1;
	hs[1] = 2;
	for (int i = 3; i < N; ++i)
	{
		if (i % 2 != 0 && prime[i] == 0)
		{

			hs[++total] = i;
		}
	}
}
int main()
{
	getPrimeTable();
	int n, i;
	while (scanf("%d", &n)&&n)
	{
		for (i = 1; i <= 664579; ++i)
		if (hs[i] > n && hs[i - 1] <= n)
			break;
		printf("%d\n", i - 1);
	}
	return 0;
}

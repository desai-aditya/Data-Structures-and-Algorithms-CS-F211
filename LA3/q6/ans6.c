// idea is similar to counting sort
// https://www.geeksforgeeks.org/sort-array-according-order-defined-another-array/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define  xlen 9
#define  ylen 3


int max(int a, int b)
{
	if(a>=b) return a;
	else return b;
}
int main()
{
	long long int x[] = {8, 3, 3, 5, 53, 6, 3, 1, 3};  // x to be sorted as y
	long long int y[] = {6, 3, 1};  // y as the 'sorter'
	
	int i;
	int xmax=-999;
	for (int i = 0; i <xlen ; ++i)   // finding max
	{
		xmax = max(xmax,x[i]);
	}
	
	int freq[xmax];
	for (int i = 0; i <= xmax; ++i)  // initialize to 0
	{
		freq[i]=0;
	}

	for (int i = 0; i < xlen; ++i)  // counting freq
	{
		freq[x[i]]++;
	}

	for (int i = 0; i < ylen; ++i)  // printing the sorted ones from y first
	{
	
		
		while(freq[y[i]])
		{
			printf("%lld ",y[i]);
			freq[y[i]]--;
		}
		
	}

	for (int i = 0; i <= xmax; ++i)  // printing the rest of the elements sorted
	{
		while(freq[i]>0)
		{
			printf("%d ", i);
			freq[i]--;
		}
	}
	printf("\n");
		
		
}
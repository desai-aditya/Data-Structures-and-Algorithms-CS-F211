//my solution for 

#include <stdio.h>
#include <stdlib.h>


int asccomparator(const void * p, const void * q)  // sorts in ascending order , comparator for qsort
{
	return ((* (int*) p) - (* (int*) q));
}

int desccomparator(const void * p, const void * q)  // sorts in descending order , comparator for qsort
{
	return ((* (int*) q) - (* (int*) p));
}



int main(int argc, char const *argv[])
{
	int i,n;
	scanf("%d",&n);

	int even=0,odd=0,evennums[n/2+1],oddnums[n/2+1];

	for (int i = 0; i < n; ++i)  // take input in both arrays, and count their num of elements
	{
		if(i%2==0)
		{
			even++;
			scanf("%d",&evennums[i/2]);
		}
		else
		{
			odd++;
			scanf("%d",&oddnums[i/2]);
		}
	}

	qsort(evennums,even,sizeof(evennums[0]),asccomparator);  //sort the even elements
	qsort(oddnums,odd,sizeof(oddnums[0]),desccomparator);  //sort the odd elements

	for (int i = 0; i < even; ++i)
	{
		printf("%d ",evennums[i] );
	}
	
	for (int i = 0; i < odd; ++i)
	{
		printf("%d ",oddnums[i] );
	}
	printf("\n");


	return 0;
}
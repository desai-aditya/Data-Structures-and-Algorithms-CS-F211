// my solution for q5
// was too lazy so implemented bubble sort as the stable sort needed here
// O(n^2) for sort since was too lazy for better sorting, could have done counting sort 
// also note the question says sort in ascending order but the example tells us otherwise
// hence I implmented it in descending order

#include<stdio.h>
#include<stdlib.h>


int numfactors(int n)  // function that returns the num of factors a number has
{
	int i,factors=1;
	int prime=0;
	while(n%2==0)
	{
		prime++;
		n=n/2;
	}
	factors*=(prime+1);
	prime=0;
	while(n%3==0)
	{
		prime++;
		n=n/3;
	}
	factors*=(prime+1);
	prime=0;

	for (int i = 5; i < n/2; i+=2)
	{
		prime=0;
		while(n%i==0)
		{
			prime++;
			n=n/i;
		}
		factors*=(prime+1);
	
	}
	
	prime=0;
	if(n>2)
	{
		prime++;
		factors*=(prime+1);
	
	}
	return factors;

}


int main(int argc, char const *argv[])
{
	int i,j,n;
	scanf("%d",&n);   //taking input

	int nums[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&nums[i]);
	}

	int factorsnums[n];

	for (int i = 0; i < n; ++i)
	{
		factorsnums[i]=numfactors(nums[i]);  // find the num of factors for each element in array
	}
/*
	for (int i = 0; i < n; ++i)
	{
		printf("%d  ",factorsnums[i] );
	}
	printf("\n");

*/
	for (int i = 0; i < n; ++i)  // implemented bubble sort for descending order, read note at top
	{
		for (int j = 0; j < n-1; ++j)
		{
			if(factorsnums[j]<factorsnums[j+1])
			{
				int temp = factorsnums[j+1];
				factorsnums[j+1]=factorsnums[j];
				factorsnums[j]=temp;
				temp=nums[j+1];
				nums[j+1]=nums[j];
				nums[j]=temp;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", nums[i]);
	}

	printf("\n");


}
// this is my solution to q7
// worst case linear time

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int i,n;
	scanf("%d",&n);  // taking input
	int arr[n];

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}

	int counter=0;   //pointer to the start of even variables
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]%2==0)//if number is even swap it with the value at counter and increment counter
		{
			int temp=arr[i];     
			arr[i]=arr[counter];
			arr[counter]=temp;
			counter++;
		}
	}

	for (int i = 0; i < n; ++i)   //print array
	{
		printf("%d ",arr[i] );
	}

	printf("\n");

	return 0;
}

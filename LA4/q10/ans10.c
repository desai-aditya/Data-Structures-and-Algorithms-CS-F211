//My solution for q10
//https://www.geeksforgeeks.org/pancake-sorting/
//basic idea is that of selection sort;
// find the max element and put it to the end
// reverse(arr,maxi) 
// reverse(arr,end)

#include<stdio.h>
#include<stdlib.h>

void reverse(int arr[], int i) // function that reverses elements from 0 to i
{
	int temp,start=0;

	while(start<i)
	{
		temp = arr[start];
		arr[start]=arr[i];
		arr[i]=temp;
		start++;
		i--;
	}
}

int maxelei(int *arr, int n)  // function to find index of max element
{
	int maxi=0,i;
	for (int i = 0; i < n; ++i)
	{
		maxi=(arr[maxi]>arr[i])?maxi:i;
	}
	return maxi;
}

void reverseSort(int * arr, int n)  // function that does the pancake sort very similar to selection sort
{
	int i;
	for (int i = 0; i < n; ++i)
	{
		int maxi=maxelei(arr,n-i);
		reverse(arr,maxi);
		reverse(arr,n-i-1);
	}

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

	reverseSort(nums,n);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ",nums[i] );
	}

	printf("\n");

}
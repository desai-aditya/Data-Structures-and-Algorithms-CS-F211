//My solution for q2

#include<stdio.h>
#include<stdlib.h>

int comparator(const void *p, const void *q)  //comparator function for qsort
{
	return ( *(int *)p - *(int *) q );
}


int bisearch(int * arr, int n, int key)  //binary seach , my implementation
{
	int left = 0;
	int right = n-1;

	while(left<=right)
	{
		int mid = (right + left)>>1;

		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[mid]>key)
		{
			right=mid-1;
		}
		else if(arr[mid]<key)
		{
			left=mid+1;
		}
	}

	return -1;
}


int main(int argc, char const *argv[])
{
	int i,j,n,X;
	scanf("%d %d",&n,&X);   //taking input

	int nums[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&nums[i]);
	}

	qsort((void *)nums,n,sizeof(nums[0]),comparator);  //using in built function to sort
	/*for (int i = 0; i < n; ++i)					   //nlogn average time
													   //n^2 worst case time
	{
		printf("%d ",nums[i] );
	}
	*/
	int flag=1;  // flag variable to chekc whether we broke out of loop
	for (int i = 0; i < n; ++i)
	{
		
		int ele=bisearch(nums,n,X-nums[i]);
		if(ele!=i&&ele!=-1)
		{
			printf("%d + %d = %d\n",nums[i],nums[ele],X );
			flag=0;
			break;
		}	
	}
	flag?printf("There are no two elements whose sum is %d\n",X ):printf("Yes\n"); //if broke out of loop 
																				   //, that means element was found

	return 0;
}
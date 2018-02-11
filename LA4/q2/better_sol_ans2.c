// this is  a better solution to q2
// https://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/
// the idea is to use a binary hashmap
// linear time worst case
// since you are checking all the elements in the array and
// a+b=sum and b+a=sum (commutative)
// hashmap keeps track of whether you crossed a
// if you did , then check whether sum - arr[i](arr[i] is b)
// has already been encountered. if it has , then it was a 
// hence a + b is sum 

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX 100000

void printPairs(int * arr, int size, int sum)
{
	int i,temp;
	bool binMap[MAX]= {0};  // initialize hashmap as 0

	for (int i = 0; i < size; ++i)    
	{
		temp = sum - arr[i];     // arr[i]+temp=sum

		if(temp>=0 && binMap[temp]==1)   //check if index is out of bounds for temp
		{								 // and that whether you already ticked the sum-arr[i] before,	
			printf("Pair with given sum %d is  (%d,%d)\n",sum,arr[i],temp ); // which means that you have the element you wanted

		}

		binMap[arr[i]]=1; //tick the element a indicating you crossed it
	}
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

	printPairs(nums,n,X);

	return 0;
}
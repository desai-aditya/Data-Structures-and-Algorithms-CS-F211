
//https://www.geeksforgeeks.org/counting-inversions/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int merge(int* arr, int *temp, int left, int mid, int right);
int _mergeSort(int *arr, int *temp, int left, int right);
int mergeSort(int * arr, int n);






int main()
{
	int i,n;
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i)  // taking input
	{
		scanf("%d",&arr[i]);
	}

	printf("%d is the num of inversions\n", mergeSort(arr,n));  // mergeSort will call other auxillary functions to help it merge and count the inversions
	


}


// function that actually counts inversions
int merge(int* arr, int *temp, int left, int mid, int right)
{
	int i, j, k;
	int inv_count=0;

	i=left; // start of left sub array
	j=mid;  // start of right sub array
	k = left;  // start of temp array
	
	while((i<=mid-1 ) && (j<=right))  // while botht the sub array ends aren't met
	{
		if(arr[i]<=arr[j])
		{
			temp[k++]=arr[i++];    // simple putting to the temp array

		}
		else
		{
			temp[k++]=arr[j++];   // simple putting to the temp array however it needs to add the inversion count

			inv_count= inv_count + mid-i;   // since all the elements in the right array are greater than the left array , 
		}									// any addition from the right array to the temp will cause the 
	}										// addition  of mid - i  to the inv_count || check reference for better understanding

	while(i<=mid - 1)
		temp[k++] = arr[i++];

	while(j<=right)
		temp[k++]= arr[j++];

	for (int i = left; i <= right; ++i)
		arr[i]=temp[i];

	return inv_count;
}



// auxillary function to help merge sort
int _mergeSort(int *arr, int *temp, int left, int right)
{
	 int mid, inv_count=0;
	 if(right>left)
	 {
	 		//divide array into two parts and 
	 		// recursively apply mergesort on both

	 		mid = (left+right)/2;   

	 		inv_count = _mergeSort(arr,temp,left,mid);   
	 		inv_count += _mergeSort(arr,temp,mid+1,right);

	 		inv_count += merge(arr,temp,left,mid+1,right);   // function to merge and actually count the inversions
	 }
	 return inv_count;
}


//merge sort that will also count the inversions

int mergeSort(int * arr, int n)
{
	int * temp =(int *)malloc(sizeof(int)*n);  // allocate separate array for putting elemnents there temporarily
	return _mergeSort(arr,temp,0, n-1);   //helper to merge and count inversions
}

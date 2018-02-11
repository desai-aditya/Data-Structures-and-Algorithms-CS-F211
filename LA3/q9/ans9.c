#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int islessthan(char * num1, char * num2)
{
	int num1len = strlen(num1);
	int num2len = strlen(num2);

	if(num1len < num2len)
		return 1;
	else if(num2len < num1len)
		return 0;
	else
	{
		int i;
		for(i=0;i<num1len;i++)
		{
			if(num1[i]<num2[i])
				return 1;
			if(num2[i]<num1[i])
				return 0;
				
		}
	}
	return 0;

	
}
int main()
{
	int n;
	// example array char * nums[n] = {"1233","1234","12414","2327","523523","64867487648764","64867487648763"};
	int i,j;
	scanf("%d ",&n);
	char  nums[n][100];
    for (i = 0; i < n; i++) {        // taking input
       		scanf("%s",nums[i]);
    	}

	for(i=0;i<n;i++)  // bubble sort but any sort can be used
	{
		for(j=0;j<n-1;j++)
		{
			if(!islessthan(nums[j],nums[j+1]))
			{
				  char temp[100];   // swapping
				   strcpy(temp,nums[j+1]);
				  strcpy(nums[j+1], nums[j]);
				  strcpy(nums[j],temp);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
	 	printf("%s\n", nums[i]);	// printing
	}
	

}
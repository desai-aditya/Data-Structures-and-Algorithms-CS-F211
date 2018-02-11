//my solution for q4
//https://www.geeksforgeeks.org/find-the-point-where-maximum-intervals-overlap/

#include<stdio.h>
#include<stdlib.h>

typedef struct student{  //element student and when he entered or exited
	int EnOrEx;
	int time;
}student;


int comparator(const void * p, const void * q)  //comparator for sorting the students according to time
{
	return (( ((student *)p)->time) - (((student *)q)->time) );
}


int main(int argc, char const *argv[])
{
	int i,j,n;
	scanf("%d",&n);   //taking input
    student students[2*n];
	//int entry[n],exit[n];
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&students[i].time);
		students[i].EnOrEx=1;  //entry = 1
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&students[n+i].time);
		students[i+n].EnOrEx=-1;  // exit =-1
	}

	qsort(students,2*n,sizeof(students[0]),comparator);

/*	for (int i = 0; i < 2*n; ++i)
	{
		printf("%d is time ",students[i].time );
		printf("%d is entry(1) or exit(-1)\n",students[i].EnOrEx );
	}*/

	int total=0,max=0,maxi=0;
	for (int i = 2*n-1; i >= 0; --i)  // its starting at end bcz we need to find the first time when the students are max
	{

		printf("%d is time|| ",students[i].time );
		printf("%d is entry(1) or exit(-1) ||",students[i].EnOrEx );

		int currenttime=students[i].time,counter=0;
		total-=students[i].EnOrEx;
		if(max>total)
		{
			max=max;
		}
		else
		{
			max=total;
			maxi=students[i].time;
		}

		printf("%d is total now \n", total);

	}

	printf("%d  ",maxi );


	printf("\n");

}
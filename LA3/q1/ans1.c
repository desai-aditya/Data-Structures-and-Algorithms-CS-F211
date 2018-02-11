// for reference check geeksforgeeks

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int max_ele(int n, int * arr);

//returns the cost of enitre operation in bringing 
//the height of all towers to equal height eq_h
long int costOfOperation(int n, int * h ,int * cost, int eq_h)
{
	// initialize cost to 0
	long int c=0;
	int i;
	for (int i = 0; i < n; ++i)
	{
		c+=abs(h[i]-eq_h)*cost[i];
	}
	return c;
}


long long int BSearch(int n, int * h, int * cost)
{
	long long int max_h = max_ele(n,h);
	long int ans = LONG_MAX;

	// do binary search for min cost

	long int high  = 1 + max_h;
	long int low = 0;

	while(high > low)
	{
		int mid = (high + low) / 2;

			//cost below mid
			long int bm = (mid > 0 )?
						costOfOperation(n,h,cost,mid-1) :
						LONG_MAX;
			//cost at mid
			long int m = costOfOperation(n,h,cost,mid);

			//cost above mid
			long int am = costOfOperation(n,h,cost,mid + 1);

			//break if the answer becomes equal to min cost m

			if(ans == m)
				break;

			//ans should hold the min cost of operation

			ans = (ans < m)? ans:m;   // ans = min(ans,m)

			//search lower cost
			if(bm<=m)
				high = mid;

			// search higher cost
			else if (am<=m)
				low = mid + 1;

	}

return ans;

}



int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int i,n;                        //// taking input
		scanf("%d",&n);
		int h[n],cost[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&h[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&cost[i]);
		}

		printf("%lld is the cost \n",BSearch(n,h,cost) );  // print answer



	}


}


int max_ele(int n, int * arr)
{
	long int i,max=-9999999;
	for (int i = 0; i < n; ++i)
	{
		max = (arr[i]>max)? arr[i]:max;
	}
	return max;
}
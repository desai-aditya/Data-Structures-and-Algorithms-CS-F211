#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
		int ans,numzeros,n,m,i,j;
		scanf("%d %d",&n,&m);
		int players[n];

		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&players[i]);
		}
		do{
			ans++;
			numzeros=0;
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n-1; ++j)
				{
					if(players[j]>players[j+1])
					{
						int temp=players[j+1];
						players[j+1]=players[j];
						players[j]=temp;
					}
				}
			}

			for(i=n-1;i>=n-m;i--)
			{
				players[i]--;
			}


			for (int i = 0; i < n; ++i)
			{
				if(players[i]==0)
					numzeros++;
			}
		}while(numzeros<=n-m);

		printf("%d\n", ans);

}
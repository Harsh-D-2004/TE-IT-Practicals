#include<stdio.h>

int main(){
	
	int n = 0;
	int m = 0;
	
	printf("Enter the number of processes : \n");
	scanf("%d" , &n);
	
	printf("Enter number of resources : \n");
	scanf("%d" , &m);
	
	int alloc[n][m];
	int maxneed[n][m];
	int available[n];
	
	printf("Enter number of allocated resources : \n");
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			scanf("%d" , &alloc[i][j]);
		}
	}
	
	printf("Enter number of max required resources : \n");
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			scanf("%d" , &maxneed[i][j]);
		}
	}
	
	printf("Enter number of available resources : \n");
	
	for(int i = 0 ; i < n ; i++){
		scanf("%d" , &available[i]);
	}
	
	int need[n][m];
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			need[i][j] = maxneed[i][j] - alloc[i][j];
		}
	}
	
	int f[n];
	int ans[n];
	int ind = 0;
	
	for(int i = 0 ; i < n ; i++){
		f[i] = 0;
	}
	
	int k , j , i = 0;
	
	int y = 0;
	for (k = 0; k < m; k++){
		for (i = 0; i < n; i++){
		    if (f[i] == 0)
		    {
			int flag = 0;
			for (j = 0; j < m; j++)
			{
			    if (need[i][j] > available[j])
			    {
				flag = 1;
				break;
			    }
			}

			if (flag == 0)
			{
			    ans[ind++] = i;
			    for (y = 0; y < m; y++)
				available[y] += alloc[i][y];
			    f[i] = 1;
			}
		    }
		}
	}

	int flag = 1;

	for (int i = 0; i < n; i++)
	{
		if (f[i] == 0)
		{
		    flag = 0;
		    printf("The following system is not safe");
		    break;
		}
	}

	if (flag == 1)
	{
		printf("Following is the SAFE Sequence\n");
		for (i = 0; i < n - 1; i++)
		    printf(" P%d ->", ans[i]);
		printf(" P%d", ans[n - 1]);
	}
	return 0;
}

#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int at[n], bt[n],wt[n],tat[n];
	printf("Enter the burst time of  %d processes: ", n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&bt[i]);
	}
	//Calculating the waiting time
	wt[1]=0;
	for(int i=2;i<=n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	}
	//Calculating the turn around time
	for(int i=2;i<=n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
	
	for (int  i=1; i<=n; i++)
    {
    	printf("Process%d	%d	%d	%d\n",i,bt[i],wt[i],tat[i]);

    }
}

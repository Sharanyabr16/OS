#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int bt[n],wt[n],tat[n],avt[n],ct[n];
	printf("Enter the burt time of  %d processes: ", n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&bt[i]);
	}
	printf("Enter the arrival time of  %d processes: ", n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&avt[i]);
	}
	//Calculating the completion time
	wt[1]=0;
	for(int i=2;i<=n;i++)
	{
		ct[i]=;
	}
	//Calculating the turn around time
	for(int i=1;i<=n;i++)
	{
		tat[i]=ct[i]-avt[i];
	}
	//Calculating the waiting time
	for(int i=1;i<=n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
	//Printing
	for (int  i=1; i<=n; i++)
    {
    	printf("Process%d	%d	%d	%d\n",i,bt[i],wt[i],tat[i]);

    }
}

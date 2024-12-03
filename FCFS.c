#include<stdio.h>
int main()
{
int n,i;
printf("Enter the number of processes:");
scanf("%d\n",&n);
int bt[n],wt[n],tat[n];
printf("\nEnter the burst time of %d processes:",n);
for(i = 1; i <= n; i++) 
{
scanf("%d", &bt[i]);
}
wt[1]=0;
for(i=2;i<=n;i++)
{
wt[i]=bt[i-1]+wt[i-1];
}
for(i=2;i<=n;i++);
{
tat[i]=bt[i]+wt[i];
}
for(int i=1;i<=n;i++)
{
printf("Process%d%d%d%d\n",i,bt[i],wt[i],tat[i]);
}
}

#include<stdio.h>
int main()
{
	int rq[100],i,n,totalheadmoment=0,initial;
	printf("enter the number of request:");
	scanf("%d",&n);
	printf("enter the request number:");
	for(i=0;i<n;i++)
	scanf("%d",&rq[i]);
	printf("enter the initial number:");
	scanf("%d",&initial);
	{
	    for(i=0;i<n;i++)
		totalheadmoment=totalheadmoment+abs(rq[i]-initial);
		initial=rq[i];
	}
	printf("enter the total head moment is :%d",totalheadmoment);
	return 0;
}W

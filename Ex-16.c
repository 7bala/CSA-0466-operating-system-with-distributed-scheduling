#include <stdio.h>
int main()
{
    int incomingStream[100];
    int pageFaults = 0;
    int frames ;
    int m, n, s, pages, i,a;
    printf("Enter no of elements :");
	scanf("%d",&a);
	for (i=0;i<a;i++)
	{
		printf("Enter elements:");
		scanf("%d",&incomingStream[i]);
	}
    pages = sizeof(incomingStream)/sizeof(incomingStream[0]);
    printf("Enter no of frames :");
	scanf("%d",&frames);
	printf("Incoming ");
	for(i=0;i<frames;i++)
	{
		printf("\t\tFrame%d",i+1);
	}
    int temp[frames];
    for(m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }
    for(m = 0; m < pages; m++)
    {
    	if(m>a-1)
    	{
    		break;
		}
        s = 0;

        for(n = 0; n < frames; n++)
        {
            if(incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        
        if((pageFaults <= frames) && (s == 0))
        {
            temp[m] = incomingStream[m];
        }
        else if(s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }
      
        printf("\n");
        printf("%d\t\t\t",incomingStream[m]);
        for(n = 0; n < frames; n++)
        {
            if(temp[n] != -1)
                printf(" %d\t\t", temp[n]);
            else
                printf(" - \t\t");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}
